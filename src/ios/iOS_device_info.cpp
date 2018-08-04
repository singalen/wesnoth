//
//  iOS_device_info.cpp
//
//  Created by Martin Hrubý on 03/08/2018.
//

#include "iOS_device_info.hpp"

#include <map>
//#include <stdio.h>
#include <sys/utsname.h>
#include <sys/stat.h>
#include <sys/sysctl.h>

struct device_info {
    std::string name;
    int screen_dpi;
    int screen_width_px;
    int screen_height_px;
    int screen_scale;
};

std::map<std::string, device_info> devices = {
    /* Last updated 03/08/2018 */
    { "i386",  { .name="iPhone Simulator", .screen_dpi=-1, .screen_width_px=0, .screen_height_px=0, .screen_scale=1 } },
    { "x86_64",  { .name="iPhone Simulator", .screen_dpi=-1, .screen_width_px=0, .screen_height_px=0, .screen_scale=1 } },
    
    { "iPhone1,1",  { .name="iPhone", .screen_dpi=163, .screen_width_px=320, .screen_height_px=480, .screen_scale=1 } },
    { "iPhone1,2",  { .name="iPhone 3G", .screen_dpi=163, .screen_width_px=320, .screen_height_px=480, .screen_scale=1 } },
    { "iPhone2,1",  { .name="iPhone 3GS", .screen_dpi=163, .screen_width_px=320, .screen_height_px=480, .screen_scale=1 } },
    { "iPhone3,1",  { .name="iPhone 4", .screen_dpi=326, .screen_width_px=640, .screen_height_px=960, .screen_scale=2 } },
    { "iPhone3,2",  { .name="iPhone 4 GSM Rev A", .screen_dpi=326, .screen_width_px=640, .screen_height_px=960, .screen_scale=2 } },
    { "iPhone3,3",  { .name="iPhone 4 CDMA", .screen_dpi=326, .screen_width_px=640, .screen_height_px=960, .screen_scale=2 } },
    { "iPhone4,1",  { .name="iPhone 4S", .screen_dpi=326, .screen_width_px=640, .screen_height_px=960, .screen_scale=2 } },
    { "iPhone5,1",  { .name="iPhone 5 (GSM)", .screen_dpi=326, .screen_width_px=640, .screen_height_px=1136, .screen_scale=2 } },
    { "iPhone5,2",  { .name="iPhone 5 (GSM+CDMA)", .screen_dpi=326, .screen_width_px=640, .screen_height_px=1136, .screen_scale=2 } },
    { "iPhone5,3",  { .name="iPhone 5C (GSM)", .screen_dpi=326, .screen_width_px=640, .screen_height_px=1136, .screen_scale=2 } },
    { "iPhone5,4",  { .name="iPhone 5C (Global)", .screen_dpi=326, .screen_width_px=640, .screen_height_px=1136, .screen_scale=2 } },
    { "iPhone6,1",  { .name="iPhone 5S (GSM)", .screen_dpi=326, .screen_width_px=640, .screen_height_px=1136, .screen_scale=2 } },
    { "iPhone6,2",  { .name="iPhone 5S (Global)", .screen_dpi=326, .screen_width_px=640, .screen_height_px=1136, .screen_scale=2 } },
    { "iPhone7,1",  { .name="iPhone 6 Plus", .screen_dpi=326, .screen_width_px=1242, .screen_height_px=2208, .screen_scale=3 } },
    { "iPhone7,2",  { .name="iPhone 6", .screen_dpi=326, .screen_width_px=750, .screen_height_px=1334, .screen_scale=2 } },
    { "iPhone8,1",  { .name="iPhone 6s", .screen_dpi=326, .screen_width_px=750, .screen_height_px=1334, .screen_scale=2 } },
    { "iPhone8,2",  { .name="iPhone 6s Plus", .screen_dpi=401, .screen_width_px=1242, .screen_height_px=2208, .screen_scale=3 } },
    { "iPhone8,3",  { .name="iPhone SE (GSM+CDMA)", .screen_dpi=326, .screen_width_px=640, .screen_height_px=1136, .screen_scale=2 } },
    { "iPhone8,4",  { .name="iPhone SE (GSM)", .screen_dpi=326, .screen_width_px=640, .screen_height_px=1136, .screen_scale=2 } },
    { "iPhone9,1",  { .name="iPhone 7 (CDMA)", .screen_dpi=326, .screen_width_px=750, .screen_height_px=1334, .screen_scale=2 } },
    { "iPhone9,2",  { .name="iPhone 7 Plus (CDMA)", .screen_dpi=401, .screen_width_px=1242, .screen_height_px=2208, .screen_scale=3 } },
    { "iPhone9,3",  { .name="iPhone 7 (GSM)", .screen_dpi=326, .screen_width_px=750, .screen_height_px=1334, .screen_scale=2 } },
    { "iPhone9,4",  { .name="iPhone 7 Plus (GSM)", .screen_dpi=401, .screen_width_px=1242, .screen_height_px=2208, .screen_scale=3 } },
    { "iPhone10,1",  { .name="iPhone 8 (CDMA)", .screen_dpi=326, .screen_width_px=750, .screen_height_px=1334, .screen_scale=2 } },
    { "iPhone10,4",  { .name="iPhone 8 (GSM)", .screen_dpi=326, .screen_width_px=750, .screen_height_px=1334, .screen_scale=2 } },
    { "iPhone10,2",  { .name="iPhone 8 Plus (CDMA)", .screen_dpi=401, .screen_width_px=1242, .screen_height_px=2208, .screen_scale=3 } },
    { "iPhone10,5",  { .name="iPhone 8 Plus (GSM)", .screen_dpi=401, .screen_width_px=1242, .screen_height_px=2208, .screen_scale=3 } },
    { "iPhone10,3",  { .name="iPhone X (CDMA)", .screen_dpi=458, .screen_width_px=1125, .screen_height_px=2436, .screen_scale=3 } },
    { "iPhone10,6",  { .name="iPhone X (GSM)", .screen_dpi=458, .screen_width_px=1125, .screen_height_px=2436, .screen_scale=3 } },
    { "iPhone11,2",  { .name="iPhone XS", .screen_dpi=458, .screen_width_px=1125, .screen_height_px=2436, .screen_scale=3 } },
    { "iPhone11,6",  { .name="iPhone XS Max", .screen_dpi=458, .screen_width_px=1242, .screen_height_px=2688, .screen_scale=3 } },
    { "iPhone11,8",  { .name="iPhone XR", .screen_dpi=326, .screen_width_px=828, .screen_height_px=1792, .screen_scale=2 } },
    
    { "iPod1,1",  { .name="1st Gen iPod", .screen_dpi=163, .screen_width_px=320, .screen_height_px=480, .screen_scale=1 } },
    { "iPod2,1",  { .name="2nd Gen iPod", .screen_dpi=163, .screen_width_px=320, .screen_height_px=480, .screen_scale=1 } },
    { "iPod3,1",  { .name="3rd Gen iPod", .screen_dpi=163, .screen_width_px=320, .screen_height_px=480, .screen_scale=1 } },
    { "iPod4,1",  { .name="4th Gen iPod", .screen_dpi=326, .screen_width_px=640, .screen_height_px=960, .screen_scale=2 } },
    { "iPod5,1",  { .name="5th Gen iPod", .screen_dpi=326, .screen_width_px=640, .screen_height_px=1136, .screen_scale=2 } },
    { "iPod7,1",  { .name="6th Gen iPod", .screen_dpi=326, .screen_width_px=640, .screen_height_px=1136, .screen_scale=2 } },
    
    { "iPad1,1",  { .name="iPad", .screen_dpi=132, .screen_width_px=1024, .screen_height_px=768, .screen_scale=1 } },
    { "iPad1,2",  { .name="iPad 3G", .screen_dpi=132, .screen_width_px=1024, .screen_height_px=768, .screen_scale=1 } },
    { "iPad2,1",  { .name="2nd Gen iPad", .screen_dpi=132, .screen_width_px=1024, .screen_height_px=768, .screen_scale=1 } },
    { "iPad2,2",  { .name="2nd Gen iPad GSM", .screen_dpi=132, .screen_width_px=1024, .screen_height_px=768, .screen_scale=1 } },
    { "iPad2,3",  { .name="2nd Gen iPad CDMA", .screen_dpi=132, .screen_width_px=1024, .screen_height_px=768, .screen_scale=1 } },
    { "iPad2,4",  { .name="2nd Gen iPad New Revision", .screen_dpi=132, .screen_width_px=1024, .screen_height_px=768, .screen_scale=1 } },
    { "iPad3,1",  { .name="3rd Gen iPad", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad3,2",  { .name="3rd Gen iPad CDMA", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad3,3",  { .name="3rd Gen iPad GSM", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad2,5",  { .name="iPad mini", .screen_dpi=163, .screen_width_px=1024, .screen_height_px=768, .screen_scale=1 } },
    { "iPad2,6",  { .name="iPad mini GSM+LTE", .screen_dpi=163, .screen_width_px=1024, .screen_height_px=768, .screen_scale=1 } },
    { "iPad2,7",  { .name="iPad mini CDMA+LTE", .screen_dpi=163, .screen_width_px=1024, .screen_height_px=768, .screen_scale=1 } },
    { "iPad3,4",  { .name="4th Gen iPad", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad3,5",  { .name="4th Gen iPad GSM+LTE", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad3,6",  { .name="4th Gen iPad CDMA+LTE", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad4,1",  { .name="iPad Air (WiFi)", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad4,2",  { .name="iPad Air (GSM+CDMA)", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad4,4",  { .name="iPad mini Retina (WiFi)", .screen_dpi=326, .screen_width_px=2048, .screen_height_px=1536, .screen_scale=2 } },
    { "iPad4,5",  { .name="iPad mini Retina (GSM+CDMA)", .screen_dpi=326, .screen_width_px=2048, .screen_height_px=1536, .screen_scale=2 } },
    { "iPad4,6",  { .name="iPad mini Retina (China)", .screen_dpi=326, .screen_width_px=2048, .screen_height_px=1536, .screen_scale=2 } },
    { "iPad4,7",  { .name="iPad mini 3 (WiFi)", .screen_dpi=326, .screen_width_px=2048, .screen_height_px=1536, .screen_scale=2 } },
    { "iPad4,8",  { .name="iPad mini 3 (GSM+CDMA)", .screen_dpi=326, .screen_width_px=2048, .screen_height_px=1536, .screen_scale=2 } },
    { "iPad4,9",  { .name="iPad Mini 3 (China)", .screen_dpi=326, .screen_width_px=2048, .screen_height_px=1536, .screen_scale=2 } },
    { "iPad5,1",  { .name="iPad mini 4 (WiFi)", .screen_dpi=326, .screen_width_px=2048, .screen_height_px=1536, .screen_scale=2 } },
    { "iPad5,2",  { .name="iPad mini 4 (GSM+CDMA)", .screen_dpi=326, .screen_width_px=2048, .screen_height_px=1536, .screen_scale=2 } },
    { "iPad5,3",  { .name="iPad Air 2 (WiFi)", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad5,4",  { .name="iPad Air 2 (Cellular)", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad6,3",  { .name="iPad Pro (9.7 inch, WiFi)", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad6,4",  { .name="iPad Pro (9.7 inch, WiFi+LTE)", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad6,7",  { .name="iPad Pro (12.9 inch, WiFi)", .screen_dpi=264, .screen_width_px=2048, .screen_height_px=2732, .screen_scale=2 } },
    { "iPad6,8",  { .name="iPad Pro (12.9 inch, WiFi+LTE)", .screen_dpi=264, .screen_width_px=2048, .screen_height_px=2732, .screen_scale=2 } },
    { "iPad6,11",  { .name="iPad (2017) (WiFi)", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad6,12",  { .name="iPad (2017) (Cellular)", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad7,1",  { .name="iPad Pro 2G (12.9 inch, WiFi)", .screen_dpi=264, .screen_width_px=2048, .screen_height_px=2732, .screen_scale=2 } },
    { "iPad7,2",  { .name="iPad Pro 2G (12.9 inch, WiFi+LTE)", .screen_dpi=264, .screen_width_px=2048, .screen_height_px=2732, .screen_scale=2 } },
    { "iPad7,3",  { .name="iPad Pro 10.5-inch", .screen_dpi=264, .screen_width_px=1668, .screen_height_px=2224, .screen_scale=2 } },
    { "iPad7,4",  { .name="iPad Pro 10.5-inch", .screen_dpi=264, .screen_width_px=1668, .screen_height_px=2224, .screen_scale=2 } },
    { "iPad7,5",  { .name="iPad (2018) (WiFi)", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad7,6",  { .name="iPad (2018) (Cellular)", .screen_dpi=264, .screen_width_px=1536, .screen_height_px=2048, .screen_scale=2 } },
    { "iPad8,1",  { .name="iPad Pro (11-inch) (Cellular)", .screen_dpi=264, .screen_width_px=1668, .screen_height_px=2388, .screen_scale=2 } },
    { "iPad8,2",  { .name="iPad Pro (11-inch) (Wi-Fi, 1 TB)", .screen_dpi=264, .screen_width_px=1668, .screen_height_px=2388, .screen_scale=2 } },
    { "iPad8,3",  { .name="iPad Pro (11-inch) (Cellular)", .screen_dpi=264, .screen_width_px=1668, .screen_height_px=2388, .screen_scale=2 } },
    { "iPad8,4",  { .name="iPad Pro (11-inch) (Cellular, 1 TB)", .screen_dpi=264, .screen_width_px=1668, .screen_height_px=2388, .screen_scale=2 } },
    { "iPad8,5",  { .name="iPad Pro 3G (12.9 inch, WiFi)", .screen_dpi=264, .screen_width_px=2048, .screen_height_px=2732, .screen_scale=2 } },
    { "iPad8,6",  { .name="iPad Pro 3G (12.9 inch, WiFi, 1 TB)", .screen_dpi=264, .screen_width_px=2048, .screen_height_px=2732, .screen_scale=2 } },
    { "iPad8,7",  { .name="iPad Pro 3G (12.9 inch, Cellular)", .screen_dpi=264, .screen_width_px=2048, .screen_height_px=2732, .screen_scale=2 } },
    { "iPad8,8",  { .name="iPad Pro 3G (12.9 inch, Cellular, 1 TB)", .screen_dpi=264, .screen_width_px=2048, .screen_height_px=2732, .screen_scale=2 } },

    { "Watch1,1",  { .name="Apple Watch 38mm case", .screen_dpi=326, .screen_width_px=272, .screen_height_px=340, .screen_scale=2 } },
    { "Watch1,2",  { .name="Apple Watch 42mm case", .screen_dpi=326, .screen_width_px=312, .screen_height_px=390, .screen_scale=2 } },
    { "Watch2,6",  { .name="Apple Watch Series 1 38mm case", .screen_dpi=326, .screen_width_px=272, .screen_height_px=340, .screen_scale=2 } },
    { "Watch2,7",  { .name="Apple Watch Series 1 42mm case", .screen_dpi=326, .screen_width_px=312, .screen_height_px=390, .screen_scale=2 } },
    { "Watch2,3",  { .name="Apple Watch Series 2 38mm case", .screen_dpi=326, .screen_width_px=272, .screen_height_px=340, .screen_scale=2 } },
    { "Watch2,4",  { .name="Apple Watch Series 2 42mm case", .screen_dpi=326, .screen_width_px=312, .screen_height_px=390, .screen_scale=2 } },
    { "Watch3,1",  { .name="Apple Watch Series 3 Cellular 38mm case", .screen_dpi=326, .screen_width_px=272, .screen_height_px=340, .screen_scale=2 } },
    { "Watch2,2",  { .name="Apple Watch Series 3 Cellular 42mm case", .screen_dpi=326, .screen_width_px=312, .screen_height_px=390, .screen_scale=2 } },
    { "Watch3,3",  { .name="Apple Watch Series 3 38mm case", .screen_dpi=326, .screen_width_px=272, .screen_height_px=340, .screen_scale=2 } },
    { "Watch3,4",  { .name="Apple Watch Series 3 42mm case", .screen_dpi=326, .screen_width_px=312, .screen_height_px=390, .screen_scale=2 } },
    { "Watch4,1",  { .name="Apple Watch Series 4 40mm case", .screen_dpi=326, .screen_width_px=324, .screen_height_px=394, .screen_scale=2 } },
    { "Watch4,2",  { .name="Apple Watch Series 4 44mm case", .screen_dpi=326, .screen_width_px=368, .screen_height_px=448, .screen_scale=2 } },
    { "Watch4,3",  { .name="Apple Watch Series 4 Cellular 40mm case", .screen_dpi=326, .screen_width_px=324, .screen_height_px=394, .screen_scale=2 } },
    { "Watch4,4",  { .name="Apple Watch Series 4 Cellular 44mm case", .screen_dpi=326, .screen_width_px=368, .screen_height_px=448, .screen_scale=2 } },
    
    { "AppleTV2,1",  { .name="Apple TV (2nd generation)", .screen_dpi=-1, .screen_width_px=0, .screen_height_px=0, .screen_scale=1 } },
    { "AppleTV3,1",  { .name="Apple TV (3rd generation)", .screen_dpi=-1, .screen_width_px=0, .screen_height_px=0, .screen_scale=1 } },
    { "AppleTV3,2",  { .name="Apple TV (3rd generation)", .screen_dpi=-1, .screen_width_px=0, .screen_height_px=0, .screen_scale=1 } },
    { "AppleTV5,3",  { .name="Apple TV (4th generation)", .screen_dpi=-1, .screen_width_px=0, .screen_height_px=0, .screen_scale=1 } },
    { "AppleTV6,2",  { .name="Apple TV 4K", .screen_dpi=-1, .screen_width_px=0, .screen_height_px=0, .screen_scale=1 } },
    
    { "AudioAccessory1,1",  { .name="HomePod", .screen_dpi=-1, .screen_width_px=0, .screen_height_px=0, .screen_scale=1 } },
    { "AudioAccessory1,2",  { .name="HomePod", .screen_dpi=-1, .screen_width_px=0, .screen_height_px=0, .screen_scale=1 } },
};

std::string get_sysinfo_by_name(const char* typeSpecifier) {
    size_t size;
    sysctlbyname(typeSpecifier, nullptr, &size, nullptr, 0);

    auto *answer = static_cast<char *>(malloc(size));
    sysctlbyname(typeSpecifier, answer, &size, nullptr, 0);

    std::string result(answer);
    free(answer);
    return result;
}

const std::string iOS_device_info::get_os_version() {
    return get_sysinfo_by_name("kern.osproductversion");
}

const std::string iOS_device_info::get_os_build_version() {
    return get_sysinfo_by_name("kern.osversion");
}

const std::string iOS_device_info::get_darwin_version() {
    return get_sysinfo_by_name("kern.osrelease");
}

const std::string iOS_device_info::get_device_identifier() {
    struct utsname systemInfo;
    uname(&systemInfo);
    
    return std::string(systemInfo.machine);
}

const std::string iOS_device_info::get_device_name() {
    if ( devices.find(get_device_identifier()) == devices.end() ) {
        return get_device_identifier();
    } else {
        return devices[get_device_identifier()].name;
    }
}

const std::string iOS_device_info::get_device_type() {
    std::string identifier = get_device_identifier();
    
    if (identifier == "x86_64" || identifier == "i386") {
        return "Simulator";
    } else if (identifier.find("iPhone") != std::string::npos) {
        return "iPhone";
    } else if (identifier.find("iPod") != std::string::npos) {
        return "iPod";
    } else if (identifier.find("iPad") != std::string::npos) {
        return "iPad";
    } else if (identifier.find("Watch") != std::string::npos) {
        return "Apple Watch";
    } else if (identifier.find("AppleTV") != std::string::npos) {
        return "Apple TV";
    } else if (identifier.find("AudioAccessory") != std::string::npos) {
        return "HomePod";
    } else {
        return "unknown";
    }
}

const int iOS_device_info::get_device_screen_dpi() {
    if ( devices.find(get_device_identifier()) == devices.end() ) {
        return 0;
    } else {
        return devices[get_device_identifier()].screen_dpi;
    }
}

const int iOS_device_info::get_device_screen_width_px() {
    if ( devices.find(get_device_identifier()) == devices.end() ) {
        return 0;
    } else {
        return devices[get_device_identifier()].screen_width_px;
    }
}

const int iOS_device_info::get_device_screen_height_px() {
    if ( devices.find(get_device_identifier()) == devices.end() ) {
        return 0;
    } else {
        return devices[get_device_identifier()].screen_height_px;
    }
}

const int iOS_device_info::get_device_screen_physical_width_px() {
    if ( devices.find(get_device_identifier()) == devices.end() ) {
        return 0;
    } else {
        if (devices[get_device_identifier()].name.find("Plus") != std::string::npos) {
            return static_cast<int> (devices[get_device_identifier()].screen_width_px / 1.15);
        } else {
            return devices[get_device_identifier()].screen_width_px;
        }
    }
}

const int iOS_device_info::get_device_screen_physical_height_px() {
    if ( devices.find(get_device_identifier()) == devices.end() ) {
        return 0;
    } else {
        if (devices[get_device_identifier()].name.find("Plus") != std::string::npos) {
            return static_cast<int> (devices[get_device_identifier()].screen_height_px / 1.15);
        } else {
            return devices[get_device_identifier()].screen_height_px;
        }
    }
}

const double iOS_device_info::get_device_screen_width_pt() {
    if ( devices.find(get_device_identifier()) == devices.end() ) {
        return 0;
    } else {
        return devices[get_device_identifier()].screen_width_px / devices[get_device_identifier()].screen_scale;
    }
}

const double iOS_device_info::get_device_screen_height_pt() {
    if ( devices.find(get_device_identifier()) == devices.end() ) {
        return 0;
    } else {
        return devices[get_device_identifier()].screen_height_px / devices[get_device_identifier()].screen_scale;
    }
}

const int iOS_device_info::get_device_screen_scale() {
    if ( devices.find(get_device_identifier()) == devices.end() ) {
        return 0;
    } else {
        return devices[get_device_identifier()].screen_scale;
    }
}
