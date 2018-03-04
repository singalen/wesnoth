#include "ios_device.h"
#include <sys/sysctl.h>

#define IFPGA                "iFPGA"

#define IPHONE_1G            "iPhone 1G"
#define IPHONE_3G            "iPhone 3G"
#define IPHONE_3GS           "iPhone 3GS"
#define IPHONE_4             "iPhone 4"
#define IPHONE_4S            "iPhone 4S"
#define IPHONE_5             "iPhone 5"
#define IPHONE_UNKNOWN       "Unknown iPhone"

#define IPOD_1G              "iPod touch 1G"
#define IPOD_2G              "iPod touch 2G"
#define IPOD_3G              "iPod touch 3G"
#define IPOD_4G              "iPod touch 4G"
#define IPOD_UNKNOWN         "Unknown iPod"

#define IPAD_1G              "iPad 1G"
#define IPAD_2G              "iPad 2G"
#define IPAD_3G              "iPad 3G"
#define IPAD_4G              "iPad 4G"
#define IPAD_UNKNOWN         "Unknown iPad"

#define APPLETV_2G           "Apple TV 2G"
#define APPLETV_3G           "Apple TV 3G"
#define APPLETV_4G           "Apple TV 4G"
#define APPLETV_UNKNOWN      "Unknown Apple TV"

#define IOS_FAMILY_UNKNOWN_DEVICE       "Unknown iOS device"

#define SIMULATOR            "iPhone Simulator"
#define SIMULATOR_IPHONE     "iPhone Simulator"
#define SIMULATOR_IPAD       "iPad Simulator"
#define SIMULATOR_APPLETV    "Apple TV Simulator"

namespace ios {

struct device_info {
	const char *hwmodel;
	int screen_dpi;
	// For now, let's use "rendered pixels".
	int screen_width_px;
	int screen_height_px;

	int screen_width_pt;
	int screen_height_pt;

	device_info(const char* hwmodel, int screen_dpi, int screen_width_px, int screen_height_px, int screen_width_pt, int screen_height_pt)
			: hwmodel(hwmodel),
			  screen_dpi(screen_dpi),
			  screen_width_px(screen_width_px),
			  screen_height_px(screen_height_px),
			  screen_width_pt(screen_width_pt),
			  screen_height_pt(screen_height_pt)
	{}
};

// https://www.paintcodeapp.com/news/ultimate-guide-to-iphone-resolutions
device_info device_infos[] = {
		device_info("iFPGA", -1, 0, 0, 0, 0),

		//Simultor
		device_info("i386", -1, 0, 0, 0, 0), // 32-bit Simulator
		device_info("x86_64", -1, 0, 0, 0, 0), // 64-bit Simulator

		//iPhone
		device_info("iPhone1,1", 163, 320, 480, 0, 0), // iPhone
		device_info("iPhone1,2", 163, 320, 480, 0, 0), // iPhone 3G
		device_info("iPhone2,1", 163, 320, 480, 0, 0), // iPhone 3GS
		device_info("iPhone3,1", 326, 640, 960, 0, 0), // iPhone 4 (GSM)
		device_info("iPhone3,3", 326, 640, 960, 0, 0), // iPhone 4 (CDMA/Verizon/Sprint)
		device_info("iPhone4,1", 326, 640, 960, 0, 0), // iPhone 4S
		device_info("iPhone5,1", 326, 640, 1136, 0, 0), // iPhone 5 (model A1428, AT&T/Canada)
		device_info("iPhone5,2", 326, 640, 1136, 0, 0), // iPhone 5 (model A1429, everything else)
		device_info("iPhone5,3", 326, 640, 1136, 0, 0), // iPhone 5c (model A1456, A1532 | GSM)
		device_info("iPhone5,4", 326, 640, 1136, 0, 0), // iPhone 5c (model A1507, A1516, A1526 (China), A1529 | Global)
		device_info("iPhone6,1", 326, 640, 1136, 0, 0), // iPhone 5s (model A1433, A1533 | GSM)
		device_info("iPhone6,2", 326, 640, 1136, 0, 0), // iPhone 5s (model A1457, A1518, A1528 (China), A1530 | Global)
		device_info("iPhone7,1", 326, 1242, 2208, 0, 0), // iPhone 6 Plus
		device_info("iPhone7,2", 326, 750, 1334, 0, 0), // iPhone 6
		device_info("iPhone8,1", 326, 750, 1334, 0, 0), // iPhone 6S

		device_info("iPhone8,2", 401, 1242, 2208, 0, 0), // iPhone 6S Plus
		device_info("iPhone8,4", 326, 640, 1136, 0, 0), // iPhone SE
		device_info("iPhone9,1", 326, 750, 1334, 0, 0), // iPhone 7 (CDMA)
		device_info("iPhone9,3", 326, 750, 1334, 0, 0), // iPhone 7 (GSM)
		device_info("iPhone9,2", 401, 1242, 2208, 0, 0), // iPhone 7 Plus (CDMA)
		device_info("iPhone9,4", 401, 1242, 2208, 0, 0), // iPhone 7 Plus (GSM)
		device_info("iPhone10,1", 326, 750, 1334, 0, 0), // iPhone 8 (CDMA)
		device_info("iPhone10,4", 326, 750, 1334, 0, 0), // iPhone 8 (GSM)
		device_info("iPhone10,2", 401, 1242, 2208, 0, 0), // iPhone 8 Plus (CDMA)
		device_info("iPhone10,5", 401, 1242, 2208, 0, 0), // iPhone 8 Plus (GSM)
		device_info("iPhone10,3", 458, 1125, 2436, 0, 0), // iPhone X (CDMA)
		device_info("iPhone10,6", 458, 1125, 2436, 0, 0), // iPhone X (GSM)

		//iPad 1
		device_info("iPad1,1", 132, 1024, 768, 0, 0), // iPad - Wifi (model A1219)
		device_info("iPad1,1", 132, 1024, 768, 0, 0), // iPad - Wifi + Cellular (model A1337)

		//iPad 2
		device_info("iPad2,1", 132, 1024, 768, 0, 0), // Wifi (model A1395)
		device_info("iPad2,2", 132, 1024, 768, 0, 0), // GSM (model A1396)
		device_info("iPad2,3", 132, 1024, 768, 0, 0), // 3G (model A1397)
		device_info("iPad2,4", 132, 1024, 768, 0, 0), // Wifi (model A1395)

		// iPad Mini
		device_info("iPad2,5", 163, 1024, 768, 0, 0), // Wifi (model A1432)
		device_info("iPad2,6", 163, 1024, 768, 0, 0), // Wifi + Cellular (model  A1454)
		device_info("iPad2,7", 163, 1024, 768, 0, 0), // Wifi + Cellular (model  A1455)

		//iPad 3
		device_info("iPad3,1", 264, 1536, 2048, 0, 0), // Wifi (model A1416)
		device_info("iPad3,2", 264, 1536, 2048, 0, 0), // Wifi + Cellular (model  A1403)
		device_info("iPad3,3", 264, 1536, 2048, 0, 0), // Wifi + Cellular (model  A1430)

		//iPad 4
		device_info("iPad3,4", 264, 1536, 2048, 0, 0), // Wifi (model A1458)
		device_info("iPad3,5", 264, 1536, 2048, 0, 0), // Wifi + Cellular (model  A1459)
		device_info("iPad3,6", 264, 1536, 2048, 0, 0), // Wifi + Cellular (model  A1460)

		//iPad AIR
		device_info("iPad4,1", 264, 1536, 2048, 0, 0), // Wifi (model A1474)
		device_info("iPad4,2", 264, 1536, 2048, 0, 0), // Wifi + Cellular (model A1475)
		device_info("iPad4,3", 264, 1536, 2048, 0, 0), // Wifi + Cellular (model A1476)

		// iPad Mini 2
		device_info("iPad4,4", 326, 2048, 1536, 0, 0), // Wifi (model A1489)
		device_info("iPad4,5", 326, 2048, 1536, 0, 0), // Wifi + Cellular (model A1490)
		device_info("iPad4,6", 326, 2048, 1536, 0, 0), // Wifi + Cellular (model A1491)

		// iPad Mini 3
		device_info("iPad4,7", 326, 2048, 1536, 0, 0), // Wifi (model A1599)
		device_info("iPad4,8", 326, 2048, 1536, 0, 0), // Wifi + Cellular (model A1600)
		device_info("iPad4,9", 326, 2048, 1536, 0, 0), // Wifi + Cellular (model A1601)

		// iPad Mini 4
		device_info("iPad5,1", 326, 2048, 1536, 0, 0), // Wifi (model A1538)
		device_info("iPad5,2", 326, 2048, 1536, 0, 0), // Wifi + Cellular (model A1550)

		//iPad AIR 2
		device_info("iPad5,3", 264, 1536, 2048, 0, 0), // Wifi (model A1566)
		device_info("iPad5,4", 264, 1536, 2048, 0, 0), // Wifi + Cellular (model A1567)

		// iPad PRO 12.9"
		device_info("iPad6,3", 0, 2048, 2732, 0, 0), // Wifi (model A1673)
		device_info("iPad6,4", 0, 2048, 2732, 0, 0), // Wifi + Cellular (model A1674)
		device_info("iPad6,4", 0, 2048, 2732, 0, 0), // Wifi + Cellular (model A1675)

		//iPad PRO 9.7"
		device_info("iPad6,7", 264, 1536, 2048, 0, 0), // Wifi (model A1584)
		device_info("iPad6,8", 264, 1536, 2048, 0, 0), // Wifi + Cellular (model A1652)

		//iPad (5th generation)
		device_info("iPad6,11", 0, 0, 0, 0, 0), // Wifi (model A1822)
		device_info("iPad6,12", 0, 0, 0, 0, 0), // Wifi + Cellular (model A1823)

		//iPad PRO 12.9" (2nd Gen)
		device_info("iPad7,1", 0, 0, 0, 0, 0), // Wifi (model A1670)
		device_info("iPad7,2", 0, 0, 0, 0, 0), // Wifi + Cellular (model A1671)
		device_info("iPad7,2", 0, 0, 0, 0, 0), // Wifi + Cellular (model A1821)

		//iPad PRO 10.5"
		device_info("iPad7,3", 0, 0, 0, 0, 0), // Wifi (model A1701)
		device_info("iPad7,4", 0, 0, 0, 0, 0), // Wifi + Cellular (model A1709)

		//iPod Touch
		device_info("iPod1,1", 0, 0, 0, 0, 0), // iPod Touch
		device_info("iPod2,1", 0, 0, 0, 0, 0), // iPod Touch Second Generation
		device_info("iPod3,1", 0, 0, 0, 0, 0), // iPod Touch Third Generation
		device_info("iPod4,1", 0, 0, 0, 0, 0), // iPod Touch Fourth Generation
		device_info("iPod5,1", 326, 640, 1136 , 0, 0), // iPod Touch 5th Generation
		device_info("iPod7,1", 0, 0, 0, 0, 0), // iPod Touch 6th Generation
};


std::string device::get_sysinfo_by_name(const char* typeSpecifier)
{
	size_t size;
	sysctlbyname(typeSpecifier, nullptr, &size, nullptr, 0);

	auto *answer = static_cast<char *>(malloc(size));
	sysctlbyname(typeSpecifier, answer, &size, nullptr, 0);

	std::string result(answer);
	free(answer);
	return result;
}

int device::get_sysinfo(int typeSpecifier)
{
	size_t size = sizeof(int);
	int results;
	int mib[2] = {CTL_HW, typeSpecifier};
	sysctl(mib, 2, &results, &size, nullptr, 0);
	return results;
}

std::string device::platform()
{
	return get_sysinfo_by_name("hw.machine");
}

std::string device::hwmodel()
{
	return get_sysinfo_by_name("hw.model");
}

int device::bus_frequency() { return get_sysinfo(HW_BUS_FREQ); }
int device::cpu_frequency() { return get_sysinfo(HW_CPU_FREQ); }
int device::cpu_count() { return get_sysinfo(HW_NCPU); }
int device::total_memory() { return get_sysinfo(HW_PHYSMEM); }
int device::user_memory() { return get_sysinfo(HW_USERMEM); }
int device::max_socket_bufferSize() { return get_sysinfo(KIPC_MAXSOCKBUF); }


device::device()
{
}

} // namespace ios
