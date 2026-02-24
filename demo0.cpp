#include "include/AppInfoNT.h"
#include "include/cornNT.h"
#include "include/SDKconstants.h"
#include "include/types.h"
#include <thread>
#include <chrono>
// #include <windows.h> // 如果使用Windows SDK请取消注释此行(使用了MFC无需取消注释)

#pragma comment(linker, "/EXPORT:_NT@8=_NTinit@8")
#pragma comment(linker, "/EXPORT:_apprunNT@8=_NTinit@8")
#pragma comment(linker, "/EXPORT:NT=_NTinit@8")
#pragma comment(linker, "/EXPORT:apprunNT=_NTinit@8")

cornNT Api;

// 插件菜单处理函数
int __stdcall _ControlPanelNT()
{
	// 建议开启GUI菜单



	return MQ::Ignore;
}

// 被启用处理函数
int __stdcall _AppStartNT()
{
	return MQ::Ignore;
}

// 被禁用处理函数 该函数下无法使用框架Api
int __stdcall _AppEndNT()
{
	return MQ::Ignore;
}

// 将被卸载处理函数 该函数下无法使用框架Api
int __stdcall _AppUnloadNT()
{
	return MQ::Ignore;
}

// 私聊消息处理函数
int __stdcall _OnPrivateNT(PrivateMsgDataNT* pData)
{
	if (!pData) return MQ::Ignore;

	PrivateMsgDataNT data = *pData;

	// 在此处添加消息处理流程
	if (data.senderQQ == data.frameworkQQ) // 过滤自己的消息(可选)
	{
		return MQ::Ignore;
	}



	return MQ::Ignore;
}

// 群聊消息处理函数
int __stdcall _OnGroupNT(GroupMsgDataNT* pData)
{
	if (!pData) return MQ::Ignore;

	GroupMsgDataNT data = *pData;

	// 在此处添加消息处理流程
	if (data.senderQQ == data.frameworkQQ) // 过滤自己的消息(可选)
	{
		return MQ::Ignore;
	}



	return MQ::Ignore;
}

// 插件欲发送消息内容处理函数
const char* __stdcall _OnPluginMessageNT(PluginSendMsgDataNT* pData)
{
	if (!pData) return "";

	PluginSendMsgDataNT data = *pData;

	// 在此处添加消息处理流程



	return data.content; // 默认不处理，返回原内容
}

// 事件消息处理函数
int __stdcall _OnEventNT(EventMsgDataNT* pData)
{
	if (!pData) return MQ::Ignore;

	EventMsgDataNT data = *pData;

	if (data.msgType == MQ::Group_FileUploaded)
	{
		// 该事件仅在萌QNT框架上，且您是使用Cat时有效！
		// data.frameworkQQ 框架QQ
		// data.operatorQQ 文件发送人的QQ
		// data.triggerQQ 此参数空
		// data.msgSeq 此参数空
		// data.timestamp 消息接收时间
		// data.groupName 来源群名称
		// data.operatorNick 发文件的人的Q名
		// data.triggerNick 此参数传递文件名
		// data.content 此传递文件ID，可以使用API:获取文件信息(数据.消息内容 )获取文件详细信息
		// data.msgSubType 固定为1，不用管
		// data.msgFlag  此参数传递文件大小，单位为KB

		// const char* ret = Api.GetFileInfo(data.frameworkQQ, data.content);
		// Api.OutputLog((std::string("消息内容:") + data.content).c_str());
		// Api.OutputLog((std::string("获取结果:") + ret).c_str());

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_MessageEssence)
	{


		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_Nudge)
	{



		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_RobotLiked)
	{



		return MQ::Ignore;
	}

	if (data.msgType == MQ::Friend_NewFriend)
	{
		// data.frameworkQQ 框架QQ
		// data.triggerQQ 新好友的QQ
		// data.timestamp 现在的时间
		// data.triggerNick 新好友的昵称

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Friend_FriendRequest)
	{
		// data.frameworQQ 框架QQ
		// data.triggerQQ 对方QQ
		// data.triggerNick 对方QQ昵称
		// data.msgSubType 为1：被添加为单向好友,为2：请求添加为好友
		// data.content 验证消息

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Friend_Recall)
	{
		// data.frameworkQQ 框架QQ
		// data.triggerQQ  撤回者QQ
		// data.msgSeq  可用于取缓存消息
		// data.timestamp 撤回消息发送时间
		// data.triggerNick 撤回者QQ昵称
		// data.content 撤回消息内容

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_MemberRecall)
	{
		// data.frameworkQQ 框架QQ
		// data.operatorQQ  撤回消息的QQ
		// data.groupID  消息撤回的群
		// data.groupName  消息撤回的群名
		// data.timestamp 现在的时间
		// data.operatorNick 撤回消息QQ的昵称
		// data.content 撤回消息的内容

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_MemberBanned)
	{
		// data.frameworkQQ 框架QQ
		// data.groupID 事件群号
		// data.operatorQQ 禁言者QQ
		// data.triggerQQ 被禁者QQ
		// data.msgSeq 被禁秒数
		// data.timestamp 被禁时间
		// data.groupName 事件群名
		// data.operatorNick 禁言者QQ昵称
		// data.triggerNick 被禁者QQ昵称

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_MemberUnbanned)
	{
		// data.frameworkQQ 框架QQ
		// data.groupID 事件群号
		// data.operatorQQ 解除者QQ
		// data.triggerQQ 被解除者QQ(首个)
		// data.timestamp 被解除时间
		// data.groupName 事件群名
		// data.operatorNick 解除者QQ昵称
		// data.triggerNick 被解除者QQ昵称(首个)

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_AdminRemoved)
	{
		// data.frameworkQQ 框架QQ
		// data.groupID 发生群号
		// data.triggerQQ  被取消者QQ
		// data.timestamp  取消时间
		// data.groupName 发生群名
		// data.triggerNick 被取消者QQ昵称

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_AdminAdded)
	{
		// data.frameworkQQ 框架QQ
		// data.groupID 发生群号
		// data.triggerQQ  被赋予者QQ
		// data.timestamp  取消时间
		// data.groupName 发生群名
		// data.triggerNick 被赋予者QQ昵称

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_GlobalBannedOn)
	{
		// data.frameworkQQ 框架QQ
		// data.groupID 启用群号
		// data.operatorQQ 开启人QQ
		// data.timestamp  开启时间
		// data.groupName 启用群名称
		// data.operatorNick 开启人QQ昵称

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_GlobalBannedOff)
	{
		// data.frameworkQQ 框架QQ
		// data.groupID 关闭群号
		// data.operatorQQ 关闭人QQ
		// data.timestamp  关闭时间
		// data.groupName 关闭群名称
		// data.operatorNick 关闭人QQ昵称

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_SelfInvited)
	{
		// data.frameworkQQ 框架QQ
		// data.groupID 被邀群号
		// data.operatorQQ 邀请者QQ
		// data.msgSeq   处理所需Seq
		// data.timestamp 邀请时间
		// data.groupName 被邀群名称
		// data.operatorNick 邀请者QQ昵称
		// data.triggerNick 本人昵称
		// data.triggerQQ  邀请者QQ

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_MemberApplying)
	{
		// data.frameworkQQ 框架QQ
		// data.groupID 被申群号
		// data.operatorQQ 邀请者QQ
		// data.msgSeq 操作所需Seq
		// data.timestamp 申请时间
		// data.groupName 被申群名称
		// data.operatorNick 邀请者QQ昵称
		// data.triggerNick 进群者QQ昵称
		// data.triggerQQ  进群者QQ
		// data.content 为：验证消息 加上 加群来源,格式为：验证消息[加群来源:xxx],如果加群者QQ存在风险被腾讯过滤,那么将加上[该帐号存在风险，请谨慎操作]后缀,验证消息内的[、]将被转义

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_MemberQuit)
	{
		// data.frameworkQQ 框架QQ
		// data.groupID 退出的群号
		// data.timestamp 退群时间
		// data.groupName 退出的群名称
		// data.triggerNick 退群者QQ昵称
		// data.triggerQQ  退群者QQ

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_MemberKicked)
	{
		// data.frameworkQQ 框架QQ
		// data.groupID 少人群号
		// data.timestamp 被踢时间
		// data.groupName 少人群名称
		// data.triggerNick 被踢者QQ昵称
		// data.triggerQQ  被踢者QQ
		// data.operatorQQ 踢人QQ
		// data.operatorNick 踢人QQ昵称

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Group_ModifyCard)
	{
		// data.frameworkQQ 框架QQ
		// data.groupID 消息群号
		// data.timestamp 修改时间(他原版写的是修改世界)
		// data.groupName 消息群名称
		// data.triggerNick 修改名片的QQ昵称
		// data.triggerQQ  修改名片的QQ
		// data.content 修改后的名片

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Frame_LoginSuccess)
	{
		// data.frameworkQQ 登录成功的框架QQ
		// data.triggerQQ 登录成功的框架QQ
		// data.triggerNick 登录成功的框架QQ昵称
		// data.timestamp 登录成功的时间戳

		return MQ::Ignore;
	}

	if (data.msgType == MQ::Frame_LoginFailed)
	{
		// data.frameworkQQ 登录失败的框架QQ
		// data.triggerQQ 登录失败的框架QQ
		// data.triggerNick 登录失败的框架QQ昵称
		// data.timestamp 登录失败的时间戳
		// data.content 登录失败信息,格式为：登录错误状态+换行+登录错误信息

		return MQ::Ignore;
	}
	return MQ::Ignore;
}




extern "C"
{
	// 初始化NT
	__declspec(dllexport)
	const char*
	__stdcall NTinit(const char* apidata, const char* pluginkey)
	{
		Api.Init(pluginkey, apidata); // API初始化，请勿删除

		AppInfoNT info;
		info.SetAppName("TODO替换为插件名");
		info.SetAppAuthor("TODO替换为作者");
		info.SetAppDescription("TODO替换为详情");
		info.SetAppVersion("TODO替换为版本");
		info.SetAppSettingsCallback((uintptr_t)&_ControlPanelNT);
		info.SetAppDisabledCallback((uintptr_t)&_AppEndNT);
		info.SetAppEnabledCallback((uintptr_t)&_AppStartNT);
		info.SetAppUninstallCallback((uintptr_t)&_AppUnloadNT);
		info.SetPrivateMsgCallback((uintptr_t)&_OnPrivateNT);
		info.SetGroupMsgCallback((uintptr_t)&_OnGroupNT);
		info.SetEventMsgCallback((uintptr_t)&_OnEventNT);
		info.SetLogOutputCallback((uintptr_t)&_OnPluginMessageNT);

		return info.取数据();
	}

}
