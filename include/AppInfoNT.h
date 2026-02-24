#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <cstdint>

class AppInfoNT {
private:
    // 內部數量定義（對應易語言常數）
    int cnt = 8;
    int cntInfo = 3;

    // 基礎成員（對應易語言程序集變量佈局）
    std::string currentAppName;
    std::string sdkVersion = "1.0.1";
    std::vector<uintptr_t> addres;
    std::vector<const char*> args;
    std::vector<std::string> infos;
    std::vector<const char*> apiNames;
    std::map<int, std::string> permissions;

    // --- 內部輔助邏輯 (嚴格對齊易語言子程序邏輯，不使用中文命名) ---

    // 對應易語言：處理應用名 (剔除非法字符)
    void internalProcessAppName(std::string& name) {
        std::string illegal = "/\\:*?\"<>|'\r\n";
        std::string result;
        for (char c : name) {
            if (illegal.find(c) == std::string::npos) {
                result += c;
            }
        }
        name = result;
    }

    // 對應易語言：字符轉義
    std::string internalEscapeString(const std::string& str) {
        std::string out;
        for (size_t i = 0; i < str.length(); ++i) {
            unsigned char c = str[i];
            if (c == '\\') out += "\\\\";
            else if (c == '\"') out += "\\\"";
            else if (c == '\r') out += "\\r";
            else if (c == '\n') out += "\\n";
            else out += c;
        }
        return out;
    }

public:
    AppInfoNT() {
        addres.resize(cnt, 0);
        infos.resize(cntInfo, "");

        args = { "author", "appv", "describe", "useproaddresNT", "banproaddresNT",
                 "unitproaddresNT", "setproaddresNT", "friendmsaddresNT",
                 "groupmsaddresNT", "eventmsaddresNT", "PmDealFuncNT" };

        // 內容完全對應易語言原版列表
        apiNames = {
            "输出日志", "发送群消息", "发送好友消息", "取好友列表", "取群列表",
            "取群成员列表", "取群名称_从缓存", "取昵称_从缓存", "撤回消息_群聊",
            "撤回消息_私聊本身", "删除群成员", "禁言群成员", "全员禁言", "取框架QQ",
            "设置管理员", "设置群名片", "退群", "解散群", "处理好友验证事件",
            "处理群验证事件", "上传群图片", "上传好友图片", "取管理层列表",
            "上传好友语音", "上传群语音", "取图片下载地址", "发送群json消息",
            "查询陌生人信息", "取群成员名片", "获取消息详细", "上传短视频",
            "自定义音乐分享", "取群成员信息", "查询某人是否被禁言", "获取skey",
            "获取pskey", "取群名称", "取昵称", "重载自身", "设置专属头衔",
            "获取推荐群聊卡片", "获取推荐好友卡片", "设置QQ头像", "获取点赞列表",
            "获取群精华消息", "获取文件信息", "获取群根目录文件列表",
            "获取群子目录文件列表", "获取群文件资源链接", "获取群公告",
            "设置群公告", "设置好友备注", "设置群备注", "设置群消息接受方式",
            "发送数据包", "分享音乐"
        };
    }

    // --- 公開接口 (變量/函數名完全不動) ---

    // 易語言：設置應用名稱
    void SetAppName(const char* name) {
        if (name) {
            std::string n = name;
            internalProcessAppName(n);
            currentAppName = n;
        }
    }

    // 易語言：設置應用作者
    void SetAppAuthor(const char* author) {
        if (author) infos[0] = internalEscapeString(author);
    }

    // 易語言：設置應用版本
    void SetAppVersion(const char* version) {
        if (version) infos[1] = internalEscapeString(version);
    }

    // 易語言：設置應用描述
    void SetAppDescription(const char* desc) {
        if (desc) infos[2] = internalEscapeString(desc);
    }

    // 易語言：應用被啟用回調地址
    void SetAppEnabledCallback(uintptr_t func) { addres[0] = func; }

    // 易語言：應用被禁用回調地址
    void SetAppDisabledCallback(uintptr_t func) { addres[1] = func; }

    // 易語言：應用被卸載回調地址
    void SetAppUninstallCallback(uintptr_t func) { addres[2] = func; }

    // 易語言：設置窗口回調地址
    void SetAppSettingsCallback(uintptr_t func) { addres[3] = func; }

    // 易語言：私聊消息回調地址
    void SetPrivateMsgCallback(uintptr_t func) { addres[4] = func; }

    // 易語言：群聊消息回調地址
    void SetGroupMsgCallback(uintptr_t func) { addres[5] = func; }

    // 易語言：事件消息回調地址
    void SetEventMsgCallback(uintptr_t func) { addres[6] = func; }

    // 易語言：日誌輸出回調地址
    void SetLogOutputCallback(uintptr_t func) { addres[7] = func; }

    // 易語言：申請API權限
    void SetApiPermission(int permission, const char* reason) {
        if (permission > 0 && permission <= (int)apiNames.size()) {
            std::string r = reason ? reason : "";
            // 模擬刪首尾空
            r.erase(0, r.find_first_not_of(" "));
            r.erase(r.find_last_not_of(" ") + 1);
            if (!r.empty()) {
                permissions[permission] = internalEscapeString(r);
            }
        }
    }

    // 易語言：獲取應用信息Json
    const char* 取数据() {
        std::stringstream ss;
        ss << "{";
        ss << "\"sdkv\":\"" << sdkVersion << "\",";
        ss << "\"appname\":\"" << currentAppName << "\"";

        for (int i = 0; i < (cntInfo + 8); ++i) {
            ss << ",\"" << args[i] << "\":";
            if (i < cntInfo) {
                ss << "\"" << infos[i] << "\"";
            }
            else {
                ss << addres[i - cntInfo];
            }
        }

        ss << ",\"data\":{\"needapilist\":{";
        bool first = true;
        for (std::map<int, std::string>::const_iterator it = permissions.begin(); it != permissions.end(); ++it) {
            if (!first) ss << ",";
            ss << "\"" << apiNames[it->first - 1] << "\":{\"desc\":\"" << it->second << "\"}";
            first = false;
        }
        ss << "}}}";

        static std::string staticJsonResult;
        staticJsonResult = ss.str();
        return staticJsonResult.c_str();
    }
};