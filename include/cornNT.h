#pragma once
#include <string>
#include "tools.h"


class cornNT
{
private:
	std::string pluginkey;
	std::string apidata;

	uintptr_t GetAPIFuncAddr(const std::string& name)
	{
		std::string strAddr = ExtractBetween(apidata, "\"" + name + "\":", ",");
		if (strAddr.empty())
		{
			strAddr = ExtractBetween(apidata, "\"" + name + "\":", "}");
		}

		return StrToUintptr(strAddr);
	}

public:
	cornNT() {};
	~cornNT() {};

	// Init Plugin Data
	void Init(const std::string& _pluginkey, const std::string& _apidata)
	{
		pluginkey = _pluginkey;
		apidata = _apidata;
	}

	// 易語言原名：输出日志
	// 參數：log(文本型, 日誌內容), textColor(整數型, 文字顏色), backColor(整數型, 背景顏色)
	// 備註：在框架日誌窗口輸出內容
	const char* OutputLog(const char* log, int textColor = 32768, int backColor = 16777215)
	{
		typedef const char* (__stdcall* Orig)(const char*, const char*, int, int);
		Orig func = (Orig)GetAPIFuncAddr("输出日志");
		if (!func) return "";
		return func(pluginkey.c_str(), log, textColor, backColor);
	}

	// 易語言原名：发送群消息
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), content(文本型, 內容), isPureText(邏輯型, 消息內容是否作為純文本發送，不解析CQ碼)
	const char* SendGroupMsg(long long frameworkQQ, long long groupID, const char* content, bool isPureText = false)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, const char*, bool);
		Orig func = (Orig)GetAPIFuncAddr("发送群消息");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, content, isPureText);
	}

	// 易語言原名：发送好友消息
	// 參數：frameworkQQ(長整數型, 框架QQ), targetQQ(長整數型, 對方QQ), content(文本型, 內容), isPureText(邏輯型, 是否純文本)
	const char* SendPrivateMsg(long long frameworkQQ, long long targetQQ, const char* content, bool isPureText = false)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, const char*, bool);
		Orig func = (Orig)GetAPIFuncAddr("发送好友消息");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, targetQQ, content, isPureText);
	}

	// 易語言原名：发送群临时消息
	// 參數：frameworkQQ(長整數型, 框架QQ), targetQQ(長整數型, 對方QQ), groupID(長整數型, 群號), content(文本型, 內容), isPureText(邏輯型, 是否純文本)
	// 備註：群號填寫代表在群發起臨時私聊消息，填寫0表示純好友私聊
	const char* SendGroupTemporaryMsg(long long frameworkQQ, long long targetQQ, long long groupID, const char* content, bool isPureText = false)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, long long, const char*, bool);
		Orig func = (Orig)GetAPIFuncAddr("发送群临时消息");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, targetQQ, groupID, content, isPureText);
	}

	// 易語言原名：取好友列表
	// 參數：frameworkQQ(長整數型, 框架QQ), structArrayAddr(好友信息NT, 參考 數組)
	// 備註：失敗或無權限返回數量0
	int GetFriendList(long long frameworkQQ, void* structArrayAddr)
	{
		typedef int(__stdcall* Orig)(const char*, long long, void*);
		Orig func = (Orig)GetAPIFuncAddr("取好友列表");
		if (!func) return 0;
		return func(pluginkey.c_str(), frameworkQQ, structArrayAddr);
	}

	// 易語言原名：取群列表
	// 參數：frameworkQQ(長整數型, 框架QQ), structArrayAddr(群信息NT, 參考 數組)
	// 備註：失敗或無權限返回數量0
	int GetGroupList(long long frameworkQQ, void* structArrayAddr)
	{
		typedef int(__stdcall* Orig)(const char*, long long, void*);
		Orig func = (Orig)GetAPIFuncAddr("取群列表");
		if (!func) return 0;
		return func(pluginkey.c_str(), frameworkQQ, structArrayAddr);
	}

	// 易語言原名：取群成员列表
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), structArrayAddr(群成員信息NT, 參考 數組)
	// 備註：失敗或無權限返回數量0
	int GetGroupMemberList(long long frameworkQQ, long long groupID, void* structArrayAddr)
	{
		typedef int(__stdcall* Orig)(const char*, long long, long long, void*);
		Orig func = (Orig)GetAPIFuncAddr("取群成员列表");
		if (!func) return 0;
		return func(pluginkey.c_str(), frameworkQQ, groupID, structArrayAddr);
	}

	// 易語言原名：取群名称_从缓存
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號)
	// 備註：可強制取出
	const char* GetGroupNameFromCache(long long frameworkQQ, long long groupID)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("取群名称_从缓存");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID);
	}

	// 易語言原名：取昵称_从缓存
	// 參數：frameworkQQ(長整數型, 框架QQ), targetQQ(長整數型, 目標QQ)
	// 備註：可強制取出
	const char* GetNickFromCache(long long frameworkQQ, long long targetQQ)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("取昵称_从缓存");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, targetQQ);
	}

	// 易語言原名：删除群成员
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), memberQQ(長整數型, 成員QQ), rejectNextApply(邏輯型, 是否拒絕再次加群申請)
	// 備註：失敗或無權限返回假
	bool RemoveGroupMember(long long frameworkQQ, long long groupID, long long memberQQ, bool rejectNextApply)
	{
		typedef bool(__stdcall* Orig)(const char*, long long, long long, long long, bool);
		Orig func = (Orig)GetAPIFuncAddr("删除群成员");
		if (!func) return false;
		return func(pluginkey.c_str(), frameworkQQ, groupID, memberQQ, rejectNextApply);
	}

	// 易語言原名：撤回消息_群聊
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), msgID(長整數型, 消息ID)
	// 備註：在群消息事件中使用，能收到並撤回自己發的消息，管理員可撤回其他人的
	bool RecallGroupMsg(long long frameworkQQ, long long groupID, long long msgID)
	{
		typedef bool(__stdcall* Orig)(const char*, long long, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("撤回消息_群聊");
		if (!func) return false;
		return func(pluginkey.c_str(), frameworkQQ, groupID, msgID);
	}

	// 易語言原名：撤回消息_私聊本身
	// 參數：frameworkQQ(長整數型, 框架QQ), otherQQ(長整數型, 對方QQ), msgID(長整數型, 消息ID)
	// 備註：用於撤回自己發的消息，其他設備的個人消息通知也可以撤回
	bool RecallPrivateMsg(long long frameworkQQ, long long otherQQ, long long msgID)
	{
		typedef bool(__stdcall* Orig)(const char*, long long, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("撤回消息_私聊本身");
		if (!func) return false;
		return func(pluginkey.c_str(), frameworkQQ, otherQQ, msgID);
	}

	// 易語言原名：禁言群成员
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), memberQQ(長整數型, 目標QQ), duration(整數型, 單位秒)
	// 備註：禁言時長為0時解除禁言，失敗或無權限返回假
	bool MuteGroupMember(long long frameworkQQ, long long groupID, long long memberQQ, int duration)
	{
		typedef bool(__stdcall* Orig)(const char*, long long, long long, long long, int);
		Orig func = (Orig)GetAPIFuncAddr("禁言群成员");
		if (!func) return false;
		return func(pluginkey.c_str(), frameworkQQ, groupID, memberQQ, duration);
	}

	// 易語言原名：全员禁言
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), isEnable(邏輯型, 是否開啟)
	// 備註：失敗或無權限返回假
	bool MuteGroupAll(long long frameworkQQ, long long groupID, bool isEnable)
	{
		typedef bool(__stdcall* Orig)(const char*, long long, long long, bool);
		Orig func = (Orig)GetAPIFuncAddr("全员禁言");
		if (!func) return false;
		return func(pluginkey.c_str(), frameworkQQ, groupID, isEnable);
	}

	// 易語言原名：取插件数据目录
	// 參數：pluginkey(文本型)
	// 備註：沒有權限限制，建議將設置文件之類的都寫這裡面，結果結尾帶"\"
	const char* GetPluginDataDir()
	{
		typedef const char* (__stdcall* Orig)(const char*);
		Orig func = (Orig)GetAPIFuncAddr("取插件数据目录");
		if (!func) return "";
		return func(pluginkey.c_str());
	}

	// 易語言原名：取框架QQ
	// 參數：pluginkey(文本型)
	// 備注：原版未註明，該函數返回格式爲:
	/*
	 * {
	 *		"QQlist": {
	 *					"[用户第一个QQ号]": {
	 *									"昵称": "[用户该QQ号昵称]",
	 *									"登录状态": "[登录完毕/未登录/其他(自测)]",
	 *									"等级信息": "[关于该QQ号等级的信息 自测]",
	 *									"收发信息": "收:[该QQ号登录期间(或许)总收信息条数],发:[该QQ号登录期间(或许)总发信息条数(大概率只记录框架发送)],速:[自测 收或发或合并]条\/min",
	 *									"登录IP": "[用户该QQ号添加时设置的IP,大部分是127.0.0.1]",
	 *									"登录协议": "[我测试时llbot和NapCat均为QQNT,建议自测]"
	 *								   }
	 *					"[用户第二个QQ号(若有)]": 以此类推...
	 *				  }
	 * }
	 */
	const char* GetFrameworkQQ()
	{
		typedef const char* (__stdcall* Orig)(const char*);
		Orig func = (Orig)GetAPIFuncAddr("取框架QQ");
		if (!func) return "";
		return func(pluginkey.c_str());
	}

	// 易語言原名：设置管理员
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), memberQQ(長整數型, 目標QQ), isCancel(邏輯型, 是否取消)
	// 備註：失敗或無權限返回假
	bool SetGroupAdmin(long long frameworkQQ, long long groupID, long long memberQQ, bool isCancel)
	{
		typedef bool(__stdcall* Orig)(const char*, long long, long long, long long, bool);
		Orig func = (Orig)GetAPIFuncAddr("设置管理员");
		if (!func) return false;
		return func(pluginkey.c_str(), frameworkQQ, groupID, memberQQ, isCancel);
	}

	// 易語言原名：设置群名片
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), memberQQ(長整數型, 目標QQ), newNick(文本型, 新暱稱)
	const char* SetGroupMemberCard(long long frameworkQQ, long long groupID, long long memberQQ, const char* newNick)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, long long, const char*);
		Orig func = (Orig)GetAPIFuncAddr("设置群名片");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, memberQQ, newNick);
	}

	// 易語言原名：退群
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號)
	bool QuitGroup(long long frameworkQQ, long long groupID)
	{
		typedef bool(__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("退群");
		if (!func) return false;
		return func(pluginkey.c_str(), frameworkQQ, groupID);
	}

	// 易語言原名：解散群
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號)
	bool DissolveGroup(long long frameworkQQ, long long groupID)
	{
		typedef bool(__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("解散群");
		if (!func) return false;
		return func(pluginkey.c_str(), frameworkQQ, groupID);
	}

	// 易語言原名：处理好友验证事件
	// 參數：frameworkQQ(長整數型, 框架QQ), flag(文本型, 事件標識), isAgree(邏輯型, 是否同意), remark(文本型, 好友備註)
	bool HandleFriendVerify(long long frameworkQQ, const char* flag, bool isAgree, const char* remark)
	{
		typedef bool(__stdcall* Orig)(const char*, long long, const char*, bool, const char*);
		Orig func = (Orig)GetAPIFuncAddr("处理好友验证事件");
		if (!func) return false;
		return func(pluginkey.c_str(), frameworkQQ, flag, isAgree, remark);
	}

	// 易語言原名：处理群验证事件
	// 參數：frameworkQQ(長整數型, 框架QQ), flag(文本型, 事件標識), msgType(整數型, 消息類型), isAgree(邏輯型, 是否同意), reason(文本型, 拒絕理由)
	bool HandleGroupVerify(long long frameworkQQ, const char* flag, int msgType, bool isAgree, const char* reason)
	{
		typedef bool(__stdcall* Orig)(const char*, long long, const char*, int, bool, const char*);
		Orig func = (Orig)GetAPIFuncAddr("处理群验证事件");
		if (!func) return false;
		return func(pluginkey.c_str(), frameworkQQ, flag, msgType, isAgree, reason);
	}

	// 易語言原名：上传群图片
	// 參數：frameworkQQ(長整數型, 框架QQ), picData(字節集, 圖片數據地址), picSize(整數型, 數據長度)
	const char* UploadGroupImg(long long frameworkQQ, void* picData, int picSize)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, void*, int);
		Orig func = (Orig)GetAPIFuncAddr("上传群图片");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, picData, picSize);
	}

	// 易語言原名：上传好友图片
	// 參數：frameworkQQ(長整數型, 框架QQ), picData(字節集, 圖片數據地址), picSize(整數型, 數據長度)
	const char* UploadFriendImg(long long frameworkQQ, void* picData, int picSize)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, void*, int);
		Orig func = (Orig)GetAPIFuncAddr("上传好友图片");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, picData, picSize);
	}

	// 易語言原名：取管理层列表
		// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號)
	const char* GetGroupAdminList(long long frameworkQQ, long long groupID)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("取管理层列表");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID);
	}

	// 易語言原名：上传群语音
	// 參數：frameworkQQ(長整數型, 框架QQ), audioData(字節集, 語音數據地址), audioSize(整數型, 數據長度)
	const char* UploadGroupAudio(long long frameworkQQ, void* audioData, int audioSize)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, void*, int);
		Orig func = (Orig)GetAPIFuncAddr("上传群语音");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, audioData, audioSize);
	}

	// 易語言原名：上传好友语音
	// 參數：frameworkQQ(長整數型, 框架QQ), audioData(字節集, 語音數據地址), audioSize(整數型, 數據長度)
	const char* UploadFriendAudio(long long frameworkQQ, void* audioData, int audioSize)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, void*, int);
		Orig func = (Orig)GetAPIFuncAddr("上传好友语音");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, audioData, audioSize);
	}

	// 易語言原名：取图片下载地址
	// 參數：frameworkQQ(長整數型, 框架QQ), cqImage(文本型, 傳入CQ碼中的圖片部分)
	const char* GetImgDownloadUrl(long long frameworkQQ, const char* cqImage)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, const char*);
		Orig func = (Orig)GetAPIFuncAddr("取图片下载地址");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, cqImage);
	}

	// 易語言原名：发送群json消息
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), jsonContent(文本型, JSON內容), isPureText(邏輯型, 是否純文本)
	const char* SendGroupJsonMsg(long long frameworkQQ, long long groupID, const char* jsonContent, bool isPureText = false)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, const char*, bool);
		Orig func = (Orig)GetAPIFuncAddr("发送群json消息");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, jsonContent, isPureText);
	}

	// 易語言原名：查询陌生人信息
	// 參數：frameworkQQ(長整數型, 框架QQ), targetQQ(長整數型, 目標QQ)
	// 備註：實際上只能查詢群員信息，返回的json 自己解析
	const char* GetStrangerInfo(long long frameworkQQ, long long targetQQ)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("查询陌生人信息");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, targetQQ);
	}

	// 易語言原名：设置账号信息
	// 參數：frameworkQQ(長整數型, 框架QQ), nick(文本型, 暱稱), sign(文本型, 簽名), gender(文本型, 性別)
	const char* SetAccountInfo(long long frameworkQQ, const char* nick, const char* sign, const char* gender)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, const char*, const char*, const char*);
		Orig func = (Orig)GetAPIFuncAddr("设置账号信息");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, nick, sign, gender);
	}

	// 易語言原名：获取登录号信息
	// 參數：frameworkQQ(長整數型, 框架QQ)
	// 備註：返回的json 包含有機器人暱稱
	const char* GetLoginAccountInfo(long long frameworkQQ)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long);
		Orig func = (Orig)GetAPIFuncAddr("获取登录号信息");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ);
	}

	// 易語言原名：取框架版本
	// 參數：pluginkey(文本型)
	const char* GetFrameworkVersion()
	{
		typedef const char* (__stdcall* Orig)(const char*);
		Orig func = (Orig)GetAPIFuncAddr("取框架版本");
		if (!func) return "";
		return func(pluginkey.c_str());
	}

	// 易語言原名：取插件文件名
	// 參數：pluginkey(文本型)
	const char* GetPluginFileName()
	{
		typedef const char* (__stdcall* Orig)(const char*);
		Orig func = (Orig)GetAPIFuncAddr("取插件文件名");
		if (!func) return "";
		return func(pluginkey.c_str());
	}

	// 易語言原名：取群成员名片
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), memberQQ(長整數型, 成員QQ)
	const char* GetGroupMemberCard(long long frameworkQQ, long long groupID, long long memberQQ)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("取群成员名片");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, memberQQ);
	}

	// 易語言原名：获取消息详细
	// 參數：frameworkQQ(長整數型, 框架QQ), msgID(長整數型, 消息ID)
	const char* GetMsgDetails(long long frameworkQQ, long long msgID)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("获取消息详细");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, msgID);
	}

	// 易語言原名：上传短视频
		// 參數：frameworkQQ(長整數型, 框架QQ), videoData(字節集, 數據地址), videoSize(整數型, 數據長度)
	const char* UploadShortVideo(long long frameworkQQ, void* videoData, int videoSize)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, void*, int);
		Orig func = (Orig)GetAPIFuncAddr("上传短视频");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, videoData, videoSize);
	}

	// 易語言原名：自定义音乐分享
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), jumpUrl(文本型, 點擊跳轉地址), fileUrl(文本型, 音源地址), title(文本型, 標題), cover(文本型, 封面地址), desc(文本型, 描述)
	const char* ShareCustomMusic(
		long long frameworkQQ,
		long long groupID,
		const char* jumpUrl,
		const char* fileUrl,
		const char* title,
		const char* cover,
		const char* desc
	)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, const char*, const char*, const char*, const char*, const char*);
		Orig func = (Orig)GetAPIFuncAddr("自定义音乐分享");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, jumpUrl, fileUrl, title, cover, desc);
	}

	// 易語言原名：取群成员信息
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), targetQQ(長整數型, 對方QQ), structAddr(群成員信息NT結構體指針, 參考)
	const char* GetGroupMemberInfo(long long frameworkQQ, long long groupID, long long targetQQ, void* structAddr)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, long long, void*);
		Orig func = (Orig)GetAPIFuncAddr("取群成员信息");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, targetQQ, structAddr);
	}

	// 易語言原名：查询某人是否被禁言
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), targetQQ(長整數型, 目標QQ)
	// 備註：可以查詢自己，返回禁言剩餘秒數，未被禁言返回0
	int IsMemberMuted(long long frameworkQQ, long long groupID, long long targetQQ)
	{
		typedef int(__stdcall* Orig)(const char*, long long, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("查询某人是否被禁言");
		if (!func) return 0;
		return func(pluginkey.c_str(), frameworkQQ, groupID, targetQQ);
	}

	// 易語言原名：获取skey
	// 參數：frameworkQQ(長整數型, 框架QQ)
	const char* GetSkey(long long frameworkQQ)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long);
		Orig func = (Orig)GetAPIFuncAddr("获取skey");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ);
	}

	// 易語言原名：获取pskey
	// 參數：frameworkQQ(長整數型, 框架QQ), domain(文本型, 域名)
	// 域名有tenpay.com;openmobile.qq.com;docs.qq.com;connect.qq.com;qzone.qq.com;vip.qq.com;gamecenter.qq.com;qun.qq.com;game.qq.com;qqweb.qq.com;ti.qq.com;office.qq.com;mail.qq.com;mma.qq.com;qidian.qq.com
	const char* GetPskey(long long frameworkQQ, const char* domain)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, const char*);
		Orig func = (Orig)GetAPIFuncAddr("获取pskey");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, domain);
	}

	// 易語言原名：取群名称
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號)
	const char* GetGroupName(long long frameworkQQ, long long groupID)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("取群名称");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID);
	}

	// 易語言原名：取昵称
	// 參數：frameworkQQ(長整數型, 框架QQ), QQ(長整數型, 目標QQ)
	const char* GetNick(long long frameworkQQ, long long QQ)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("取昵称");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, QQ);
	}

	// 易語言原名：重载自身
	// 參數：newDllPath(文本型, 新dll路徑)
	// 備註：填入新路徑可實現替換更新，默認值為"empty"
	void ReloadSelf(const char* newDllPath = "empty")
	{
		typedef void(__stdcall* Orig)(const char*, const char*);
		Orig func = (Orig)GetAPIFuncAddr("重载自身");
		if (func) func(pluginkey.c_str(), newDllPath);
	}

	// 易語言原名：设置专属头衔
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), targetQQ(長整數型, 目標QQ), title(文本型, 頭銜內容)
	const char* SetGroupSpecialTitle(long long frameworkQQ, long long groupID, long long targetQQ, const char* title)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, long long, const char*);
		Orig func = (Orig)GetAPIFuncAddr("设置专属头衔");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, targetQQ, title);
	}

	// 易語言原名：获取推荐群聊卡片
	// 參數：frameworkQQ(長整數型, 框架QQ), targetGroupID(長整數型, 目標群號)
	const char* GetRecommendGroupCard(long long frameworkQQ, long long targetGroupID)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("获取推荐群聊卡片");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, targetGroupID);
	}

	// 易語言原名：获取推荐好友卡片
	// 參數：frameworkQQ(長整數型, 框架QQ), targetQQ(長整數型, 目標QQ)
	const char* GetRecommendFriendCard(long long frameworkQQ, long long targetQQ)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("获取推荐好友卡片");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, targetQQ);
	}

	// 易語言原名：设置QQ头像
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 來源群號), filePathOrUrl(文本型, 本地路徑或URL)
	const char* SetQQAvatar(long long frameworkQQ, long long groupID, const char* filePathOrUrl)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, const char*);
		Orig func = (Orig)GetAPIFuncAddr("设置QQ头像");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, filePathOrUrl);
	}

	// 易語言原名：获取点赞列表
	// 參數：frameworkQQ(長整數型, 框架QQ)
	const char* GetLikeList(long long frameworkQQ)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long);
		Orig func = (Orig)GetAPIFuncAddr("获取点赞列表");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ);
	}

	// 易語言原名：获取群精华消息
		// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號)
	const char* GetGroupEssenceMsg(long long frameworkQQ, long long groupID)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("获取群精华消息");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID);
	}

	// 易語言原名：获取文件信息
	// 參數：frameworkQQ(長整數型, 框架QQ), fileID(文本型, 文件ID)
	const char* GetFileInfo(long long frameworkQQ, const char* fileID)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, const char*);
		Orig func = (Orig)GetAPIFuncAddr("获取文件信息");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, fileID);
	}

	// 易語言原名：获取群根目录文件列表
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號)
	const char* GetGroupRootFileList(long long frameworkQQ, long long groupID)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("获取群根目录文件列表");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID);
	}

	// 易語言原名：获取群子目录文件列表
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), folderID(文本型, 目錄ID), fileCount(整數型, 獲取數量)
	const char* GetGroupSubFileList(long long frameworkQQ, long long groupID, const char* folderID, int fileCount)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, const char*, int);
		Orig func = (Orig)GetAPIFuncAddr("获取群子目录文件列表");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, folderID, fileCount);
	}

	// 易語言原名：获取群文件资源链接
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), fileID(文本型, 文件ID)
	const char* GetGroupFileResourceUrl(long long frameworkQQ, long long groupID, const char* fileID)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, const char*);
		Orig func = (Orig)GetAPIFuncAddr("获取群文件资源链接");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, fileID);
	}

	// 易語言原名：获取群公告
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號)
	const char* GetGroupNotice(long long frameworkQQ, long long groupID)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long);
		Orig func = (Orig)GetAPIFuncAddr("获取群公告");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID);
	}

	// 易語言原名：设置群公告
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), content(文本型, 內容), imagePathOrUrl(文本型, 圖片路徑或URL)
	const char* SetGroupNotice(long long frameworkQQ, long long groupID, const char* content, const char* imagePathOrUrl)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, const char*, const char*);
		Orig func = (Orig)GetAPIFuncAddr("设置群公告");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, content, imagePathOrUrl);
	}

	// 易語言原名：设置好友备注
	// 參數：frameworkQQ(長整數型, 框架QQ), targetQQ(長整數型, 目標QQ), remark(文本型, 新備註文本)
	const char* SetFriendRemark(long long frameworkQQ, long long targetQQ, const char* remark)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, const char*);
		Orig func = (Orig)GetAPIFuncAddr("设置好友备注");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, targetQQ, remark);
	}

	// 易語言原名：设置群备注
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), remark(文本型, 新備註文本)
	const char* SetGroupRemark(long long frameworkQQ, long long groupID, const char* remark)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, const char*);
		Orig func = (Orig)GetAPIFuncAddr("设置群备注");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, remark);
	}

	// 易語言原名：设置群消息接受方式
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), mode(整數型, 方式)
	// 備註：1接收並提醒, 2收進助手, 3屏蔽, 4接收不提醒
	const char* SetGroupMsgReceiveMode(long long frameworkQQ, long long groupID, int mode)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, int);
		Orig func = (Orig)GetAPIFuncAddr("设置群消息接受方式");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, mode);
	}

	// 易語言原名：发送数据包
	// 參數：frameworkQQ(長整數型, 框架QQ), jsonPacket(文本型, JSON數據包), waitTimeMs(整數型, 等待時長ms)
	const char* SendPacket(long long frameworkQQ, const char* jsonPacket, int waitTimeMs)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, const char*, int);
		Orig func = (Orig)GetAPIFuncAddr("发送数据包");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, jsonPacket, waitTimeMs);
	}

	// 易語言原名：分享音乐
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 目標群/QQ), songName(文本型), artist(文本型), jumpUrl(文本型), fileUrl(文本型), coverUrl(文本型), shareType(整數型, 0私聊 1群聊)
	const char* ShareMusic(
		long long frameworkQQ,
		long long groupID,
		const char* songName,
		const char* artist,
		const char* jumpUrl,
		const char* fileUrl,
		const char* coverUrl,
		int shareType
	)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, const char*, const char*, const char*, const char*, const char*, int);
		Orig func = (Orig)GetAPIFuncAddr("分享音乐");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, groupID, songName, artist, jumpUrl, fileUrl, coverUrl, shareType);
	}

	// 易語言原名：点赞
	// 參數：frameworkQQ(長整數型, 框架QQ), targetQQ(長整數型, 對方QQ), likeCount(整數型，點讚次數)
	// 備註：調用框架給指定QQ名片點讚
	const char* SendLike(long long frameworkQQ, long long targetQQ, int likeCount)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, long long, int);
		Orig func = (Orig)GetAPIFuncAddr("点赞");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, targetQQ, likeCount);
	}

	// 易語言原名：设置群名
	// 參數：frameworkQQ(長整數型, 框架QQ), groupID(長整數型, 群號), newGroupName(文本型, 新群名)
	// 備註：修改指定群聊的名稱，需管理員權限
	const char* SetGroupName(long long frameworkQQ, long long groupID, const char* newGroupName)
	{
		typedef const char*(__stdcall* Orig)(const char*, long long, long long, const char*);
		Orig func = (Orig)GetAPIFuncAddr("设置群名");
		if (!func) return false;
		return func(pluginkey.c_str(), frameworkQQ, groupID, newGroupName);
	}

	// 易語言原名：设置在线状态
	// 參數：frameworkQQ(長整數型, 框架QQ), status(整數型, 狀態碼),extStatus(整數型，狀態碼_外部) battery(整數型, 電量)
	// 備註：狀態碼：11(在線), 31(離開), 41(隱身), 50(忙碌), 60(Q我吧), 70(請勿打擾)；電量：1-100
	const char* SetOnlineStatus(long long frameworkQQ, int status, int extStatus, int battery = 100)
	{
		typedef const char* (__stdcall* Orig)(const char*, long long, int, int, int);
		Orig func = (Orig)GetAPIFuncAddr("设置在线状态");
		if (!func) return "";
		return func(pluginkey.c_str(), frameworkQQ, status, extStatus, battery);
	}
};
