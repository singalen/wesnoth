#ifndef PROJECT_device_H
#define PROJECT_device_H

#include <string>

//typedef enum {
//	UIDeviceUnknown,
//
//	UIDeviceSimulator,
//	UIDeviceSimulatoriPhone,
//	UIDeviceSimulatoriPad,
//	UIDeviceSimulatorAppleTV,
//
//	UIDevice1GiPhone,
//	UIDevice3GiPhone,
//	UIDevice3GSiPhone,
//	UIDevice4iPhone,
//	UIDevice4SiPhone,
//	UIDevice5iPhone,
//
//	UIDevice1GiPod,
//	UIDevice2GiPod,
//	UIDevice3GiPod,
//	UIDevice4GiPod,
//
//	UIDevice1GiPad,
//	UIDevice2GiPad,
//	UIDevice3GiPad,
//	UIDevice4GiPad,
//
//	UIDeviceAppleTV2,
//	UIDeviceAppleTV3,
//	UIDeviceAppleTV4,
//
//	UIDeviceUnknowniPhone,
//	UIDeviceUnknowniPod,
//	UIDeviceUnknowniPad,
//	UIDeviceUnknownAppleTV,
//	UIDeviceIFPGA,
//} UIDevicePlatform;

namespace ios {

enum {
	iPhone,
	iPod,
	iPad,
	AppleTV,
	Unknown,
} Family;

class device {
	static device instance_;

	device();

	std::string get_sysinfo_by_name(const char* typeSpecifier);
	int get_sysinfo(int typeSpecifier);

	std::string platform();
	std::string hwmodel();
	int bus_frequency();
	int cpu_frequency();
	int cpu_count();
	int total_memory();
	int user_memory();
	int max_socket_bufferSize();

public:
	static const device& instance();

	int screen_dpi() const;
	int screen_width_px() const;
	int screen_height_px() const;
	int screen_width_in() const;
	int screen_height_in() const;
};

} // namespace ios

#endif //PROJECT_device_H
