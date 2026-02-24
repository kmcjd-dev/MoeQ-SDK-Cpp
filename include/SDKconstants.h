#pragma once

namespace MQ {

    // === 消息处理结果 ===
    constexpr int Intercept = 1; // 消息处理_拦截NT
    constexpr int Ignore = 0; // 消息处理_忽略NT

    // === 群事件类型 ===
    constexpr int Group_ModifyCard = 36;   // 群事件_修改群名片
    constexpr int Group_MemberBanned = 7;    // 群事件_某人被禁言NT
    constexpr int Group_MemberRecall = 8;    // 群事件_某人撤回事件NT
    constexpr int Group_AdminRemoved = 9;    // 群事件_某人被取消管理NT
    constexpr int Group_AdminAdded = 10;   // 群事件_某人被赋予管理NT
    constexpr int Group_GlobalBannedOn = 11;   // 群事件_开启全员禁言NT
    constexpr int Group_GlobalBannedOff = 12;   // 群事件_关闭全员禁言NT
    constexpr int Group_MemberUnbanned = 28;   // 群事件_某人被解除禁言NT
    constexpr int Group_MemberQuit = 5;    // 群事件_某人退出了群NT
    constexpr int Group_MemberKicked = 6;    // 群事件_某人被踢出群NT
    constexpr int Group_MemberInvited = 25;   // 群事件_某人被邀请入群NT
    constexpr int Group_MemberJoined = 2;    // 群事件_某人加入了群NT
    constexpr int Group_MemberApplying = 3;    // 群事件_某人申请加群NT
    constexpr int Group_SelfInvited = 1;    // 群事件_我被邀请加入群NT
    constexpr int Group_MessageEssence = 1001; // 群事件_消息被设精华NT
    constexpr int Group_Nudge = 1002; // 群事件_戳一戳NT
    constexpr int Group_RobotLiked = 1003; // 群事件_机器人被点赞NT
    constexpr int Group_FileUploaded = 1004; // 群事件_某人上传群文件NT

    // === 好友事件类型 ===
    constexpr int Friend_NewFriend = 104; // 好友事件_有新好友NT
    constexpr int Friend_Recall = 103; // 好友事件_某人撤回事件NT
    constexpr int Friend_FriendRequest = 105; // 好友事件_好友请求NT

    // === 响应状态 ===
    constexpr int Resp_Refuse = 10; // 启用响应_拒绝NT
    constexpr int Resp_Finished = 11; // 启用响应_完成NT

    // === 框架事件 ===
    constexpr int Frame_LoginFailed = 38; // 框架事件_登录失败NT
    constexpr int Frame_LoginSuccess = 31; // 框架事件_登录成功NT
    constexpr int Frame_Logout = 32; // 框架事件_账号下线NT

    // === 权限 ID ===
    constexpr int Perm_OutputLog = 1;  // 权限_输出日志NT
    constexpr int Perm_SendGroupMsg = 2;  // 权限_发送群消息NT
    constexpr int Perm_SendPrivateMsg = 3;  // 权限_发送好友消息NT
    constexpr int Perm_GetFriendList = 4;  // 权限_取好友列表NT
    constexpr int Perm_GetGroupList = 5;  // 权限_取群列表NT
    constexpr int Perm_GetGroupMemberList = 6;  // 权限_取群成员列表NT
    constexpr int Perm_GetGroupNameFromCache = 7;  // 权限_取群名称_从缓存NT
    constexpr int Perm_GetNickFromCache = 8;  // 权限_取昵称_从缓存NT
    constexpr int Perm_RecallGroupMsg = 9;  // 权限_撤回消息_群聊NT
    constexpr int Perm_RecallPrivateMsg = 10; // 权限_撤回消息_私聊本身NT
    constexpr int Perm_RemoveGroupMember = 11; // 权限_删除群成员NT
    constexpr int Perm_BanGroupMember = 12; // 权限_禁言群成员NT
    constexpr int Perm_BanAll = 13; // 权限_全员禁言NT
    constexpr int Perm_GetFrameworkQQ = 14; // 权限_取框架QQNT
    constexpr int Perm_SetAdmin = 15; // 权限_设置管理员NT
    constexpr int Perm_SetGroupCard = 16; // 权限_设置群名片NT
    constexpr int Perm_QuitGroup = 17; // 权限_退群NT
    constexpr int Perm_DissolveGroup = 18; // 权限_解散群NT
    constexpr int Perm_HandleFriendVerify = 19; // 权限_处理好友验证事件NT
    constexpr int Perm_HandleGroupVerify = 20; // 权限_处理群验证事件NT
    constexpr int Perm_UploadGroupImg = 21; // 权限_上传群图片NT
    constexpr int Perm_UploadPrivateImg = 22; // 权限_上传好友图片NT
    constexpr int Perm_GetAdminList = 23; // 权限_取管理层列表NT
    constexpr int Perm_UploadPrivateAudio = 24; // 权限_上传好友语音NT
    constexpr int Perm_UploadGroupAudio = 25; // 权限_上传群语音NT
    constexpr int Perm_GetImgDownloadUrl = 26; // 权限_取图片下载地址NT
    constexpr int Perm_SendGroupJson = 27; // 权限_发送群json消息NT
    constexpr int Perm_QueryStrangerInfo = 28; // 权限_查询陌生人信息NT
    constexpr int Perm_GetGroupMemberCard = 29; // 权限_取群成员名片NT
    constexpr int Perm_GetMsgDetail = 30; // 权限_获取消息详细NT
    constexpr int Perm_UploadVideo = 31; // 权限_上传短视频NT
    constexpr int Perm_ShareMusic = 32; // 权限_自定义音乐分享NT
    constexpr int Perm_GetGroupMemberInfo = 33; // 权限_取群成员信息NT
    constexpr int Perm_IsMemberBanned = 34; // 权限_查询某人是否被禁言NT
    constexpr int Perm_GetSkey = 35; // 权限_获取skeyNT
    constexpr int Perm_GetPskey = 36; // 权限_获取pskeyNT
    constexpr int Perm_GetGroupName = 37; // 权限_取群名称NT
    constexpr int Perm_GetNickname = 38; // 权限_取昵称NT
    constexpr int Perm_ReloadSelf = 39; // 权限_重载自身NT
    constexpr int Perm_SetSpecialTitle = 40; // 权限_设置专属头衔NT
    constexpr int Perm_GetRecommendGroup = 41; // 权限_获取推荐群聊卡片NT
    constexpr int Perm_GetRecommendFriend = 42; // 权限_获取推荐好友卡片NT
    constexpr int Perm_SetQQAvatar = 43; // 权限_设置QQ头像NT
    constexpr int Perm_GetLikeList = 44; // 权限_获取点赞列表NT
    constexpr int Perm_GetEssenceList = 45; // 权限_获取群精华消息NT
    constexpr int Perm_GetFileInfo = 46; // 权限_获取文件信息NT
    constexpr int Perm_GetGroupRootDir = 47; // 权限_获取群根目录文件列表NT
    constexpr int Perm_GetGroupSubDir = 48; // 权限_获取群子目录文件列表NT
    constexpr int Perm_GetGroupFileUrl = 49; // 权限_获取群文件资源链接NT
    constexpr int Perm_GetGroupNotice = 50; // 权限_获取群公告NT
    constexpr int Perm_SetGroupNotice = 51; // 权限_设置群公告NT
    constexpr int Perm_SetFriendRemark = 52; // 权限_设置好友备注NT
    constexpr int Perm_SetGroupRemark = 53; // 权限_设置群备注NT
    constexpr int Perm_SetMsgReceiveType = 54; // 权限_设置群消息接受方式NT
    constexpr int Perm_SendPacket = 55; // 权限_发送数据包NT

    // === QQ 状态码 ===
    constexpr int Status_Online = 10;   // 状态码_在线
    constexpr int Status_QMe = 60;   // 状态码_Q我吧
    constexpr int Status_Away = 30;   // 状态码_离开
    constexpr int Status_Busy = 50;   // 状态码_忙碌
    constexpr int Status_DontDisturb = 70;   // 状态码_请勿打扰
    constexpr int Status_Invisible = 40;   // 状态码_隐身

    // === 合并转发类型 ===
    constexpr const char* Forward_Text = "文本消息";
    constexpr const char* Forward_Face = "表情消息";
    constexpr const char* Forward_Image = "图片消息";
    constexpr const char* Forward_Reply = "回复消息";
    constexpr const char* Forward_Json = "json消息";
    constexpr const char* Forward_Video = "视频消息";
    constexpr const char* Forward_Markdown = "markdown消息";

}