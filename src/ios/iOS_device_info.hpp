//
//  iOS_device_info.hpp
//
//  Created by Martin Hrubý on 03/08/2018.
//

#ifndef iOS_device_info_hpp
#define iOS_device_info_hpp

#include <string>

class iOS_device_info
{
public:
    static const std::string get_os_version();
    static const std::string get_os_build_version();
    static const std::string get_darwin_version();
    static const std::string get_device_identifier();
    static const std::string get_device_name();
    static const std::string get_device_type();
    static const int get_device_screen_dpi();
    static const int get_device_screen_width_px();
    static const int get_device_screen_height_px();
    static const int get_device_screen_physical_width_px();
    static const int get_device_screen_physical_height_px();
    static const double get_device_screen_width_pt();
    static const double get_device_screen_height_pt();
    static const int get_device_screen_scale();
    
private:
    iOS_device_info() {}
};

#endif /* iOS_device_info_hpp */
