#pragma once
#include <string>
#include <cstdio>
#include <algorithm>
#include <ctime>

// 10位時間戳轉長整數
inline long long TimestampToLong(int timestamp)
{
    return (long long)(unsigned int)timestamp;
}

// 10位時間戳轉日期 (安全版：返回 std::string 避免 static 緩存污染)
inline std::string TimestampToDateTimeStr(int timestamp)
{
    time_t rawtime = (time_t)(unsigned int)timestamp;
    struct tm timeinfo;

#ifdef _WIN32
    localtime_s(&timeinfo, &rawtime); // Windows 下安全用法
#else
    struct tm* staticTime = localtime(&rawtime);
    if (!staticTime) return "";
    timeinfo = *staticTime;
#endif

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
    return std::string(buffer);
}

// 取騰訊換行符
inline const char* GetQQLineBreak(bool isAndroid = false)
{
    return isAndroid ? "\n" : "\r";
}

// 處理消息換行符
inline void ProcessLineBreaks(std::string& content)
{
    if (content.empty()) return;
    size_t pos = 0;
    while ((pos = content.find("\r\n", pos)) != std::string::npos)
    {
        content.replace(pos, 2, "\x01");
        pos += 1;
    }
    pos = 0;
    while ((pos = content.find("\n", pos)) != std::string::npos)
    {
        content.replace(pos, 1, "\r\n");
        pos += 2;
    }
    pos = 0;
    while ((pos = content.find("\r", pos)) != std::string::npos)
    {
        content.replace(pos, 1, "\r\n");
        pos += 2;
    }
    pos = 0;
    while ((pos = content.find("\x01", pos)) != std::string::npos)
    {
        content.replace(pos, 1, "\r\n");
        pos += 2;
    }
}

// 組cookie (優雅處理 10 位補零)
inline std::string MakeCookie(long long QQ, const char* skey, const char* pskey)
{
    char uinStr[20] = { 0 };
    // 確使用的是 %010lld 而非 %01011d
    sprintf(uinStr, "%010lld", QQ);

    std::string cookie;
    cookie.reserve(128);
    cookie += "uin=o";
    cookie += uinStr;
    cookie += "; p_uin=o";
    cookie += uinStr;
    cookie += "; skey=";
    cookie += (skey ? skey : "");
    cookie += "; p_skey=";
    cookie += (pskey ? pskey : "");
    cookie += ";";

    return cookie;
}

// 取身份組自定義顏色代碼
inline long long GetGroupCustomColor(int R, int G, int B)
{
    unsigned char colorBytes[8] = { 0 };
    colorBytes[0] = (unsigned char)B;
    colorBytes[1] = (unsigned char)G;
    colorBytes[2] = (unsigned char)R;
    colorBytes[3] = 255;
    return *(long long*)colorBytes;
}

// 身份組顏色代碼十到RGB
inline void ColorCodeToRGB(long long colorCode, int& R, int& G, int& B)
{
    unsigned char* bin = (unsigned char*)&colorCode;
    B = bin[0];
    G = bin[1];
    R = bin[2];
}

// 身份組顏色代碼十到十六 (返回 std::string 確保線程安全)
inline std::string ColorCodeToHex(long long colorCode)
{
    int R, G, B;
    ColorCodeToRGB(colorCode, R, G, B);
    char hexStr[10];
    sprintf(hexStr, "%02X%02X%02X", R, G, B);
    return std::string(hexStr);
}