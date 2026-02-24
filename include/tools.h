#pragma once
#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>

inline std::string ExtractBetween(const std::string& str, const std::string& start, const std::string& end)
{
    // 查找起始字符串的位置
    size_t startPos = str.find(start);
    if (startPos == std::string::npos) {
        return "";  // 未找到起始字符串
    }

    // 从起始字符串末尾开始查找结束字符串
    size_t endPos = str.find(end, startPos + start.length());
    if (endPos == std::string::npos) {
        return "";  // 未找到结束字符串
    }

    // 截取两个字符串之间的部分
    return str.substr(startPos + start.length(), endPos - (startPos + start.length()));
}

inline uintptr_t StrToUintptr(const std::string& str)
{
    uintptr_t ret = 0;

    if (sizeof(void*) == 4)
    {
        try
        {
            ret = (uint32_t)std::stoul(str);
        }
        catch(const std::invalid_argument& e)
        {
            ret = 0;
        }
        catch (const std::out_of_range& e)
        {
            ret = 0;
        }
    }
    else if (sizeof(void*) == 8)
    {
        try
        {
            ret = (uint64_t)std::stoull(str);
        }
        catch (const std::invalid_argument& e)
        {
            ret = 0LL;
        }
        catch (const std::out_of_range& e)
        {
            ret = 0LL;
        }
    }

    return ret;
}

inline std::string StringToHex(const std::string& input) {
    std::stringstream ss;
    ss << std::hex << std::setfill('0') << std::uppercase;
    for (unsigned char c : input) {
        ss << std::setw(2) << static_cast<int>(c) << " ";
    }
    return ss.str();
}