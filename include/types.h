#pragma once
struct FriendGroup
{
    const char* groupID;          // 文本型：分組ID
    const char* groupSortID;      // 文本型：分組排序ID
    const char* groupName;        // 文本型：分組名
    const char* friendCount;      // 文本型：好友數量
    const char* onlineFriendCount;// 文本型：在線好友數量
    const char* friendDetailList; // 文本型：好友詳情列表
};

// 數據類型：陌生人詳細信息
struct StrangerInfoNT
{
    const char* user_id;       // 文本型
    const char* uid;           // 文本型
    const char* uin;           // 文本型
    const char* nickname;      // 文本型：暱稱
    int age;                   // 整數型：年齡
    const char* qid;           // 文本型
    int qqLevel;               // 整數型：QQ等級
    const char* sex;           // 文本型：性別
    const char* long_nick;     // 文本型：個性簽名
    long long reg_time;        // 長整數型：註冊時間戳
    bool is_vip;               // 邏輯型：是否會員
    bool is_years_vip;         // 邏輯型：是否年費會員
    int vip_level;             // 整數型：會員等級
    const char* remark;        // 文本型：備註
    int status;                // 整數型
    int login_days;            // 整數型：連續登錄天數
};

// 數據類型：群消息數據NT
struct GroupMsgDataNT
{
    long long senderQQ;        // 長整數型：發送人QQ
    long long frameworkQQ;     // 長整數型：框架QQ
    int msgID;                 // 整數型：消息ID
    int receiveTime;           // 整數型：消息接收時間
    long long groupID;         // 長整數型：消息群號
    const char* groupName;     // 文本型：來源群名稱
    const char* senderCard;    // 文本型：發送人群名片
    int sendTime;              // 整數型：消息發送時間
    const char* rawMsg;        // 文本型：原始消息
    const char* content;       // 文本型：消息內容
    const char* senderNick;    // 文本型：發送人暱稱
};

// 數據類型：私聊消息數據NT
struct PrivateMsgDataNT
{
    long long senderQQ;        // 長整數型：發送人QQ
    long long frameworkQQ;     // 長整數型：框架QQ
    int msgID;                 // 整數型：消息ID
    int sendTime;              // 整數型：消息發送時間
    const char* content;       // 文本型：消息內容
    int msgType;               // 整數型：消息類型
    long long eventQQ;         // 長整數型：來源事件QQ
    const char* eventNick;     // 文本型：來源事件QQ暱稱
    const char* rawMsg;        // 文本型：原始消息
    long long groupID;         // 長整數型：消息群號（若是群臨時消息則有值）
    const char* groupName;     // 文本型：來源群名稱
};

// 數據類型：事件消息數據NT
struct EventMsgDataNT
{
    long long frameworkQQ;     // 長整數型：框架QQ
    long long groupID;         // 長整數型：來源群號
    long long operatorQQ;      // 長整數型：操作QQ
    long long triggerQQ;       // 長整數型：觸發QQ
    long long msgSeq;          // 長整數型：消息Seq
    int timestamp;             // 整數型：消息時間戳
    const char* groupName;     // 文本型：來源群名
    const char* operatorNick;  // 文本型：操作QQ暱稱
    const char* triggerNick;   // 文本型：觸發QQ暱稱
    const char* content;       // 文本型：消息內容
    int msgType;               // 整數型：消息類型
    int msgSubType;            // 整數型：消息子類型
    const char* msgFlag;       // 文本型：消息flag
};

// 數據類型：好友信息NT
struct FriendInfoNT
{
    long long account;         // 長整數型：賬號
    const char* nickname;      // 文本型：暱稱
    const char* remark;        // 文本型：備註名
    const char* sex;           // 文本型：性別
    int level;                 // 整數型：等級
};

// 數據類型：群信息NT
struct GroupInfoNT
{
    long long groupID;         // 長整數型：群號
    const char* groupName;     // 文本型：群名稱
    long long memberCount;     // 長整數型：群人數
    long long maxMemberCount;  // 長整數型：群人數上限
};

// 數據類型：插件消息發送數據NT
struct PluginSendMsgDataNT
{
    const char* pluginFileName; // 文本型：插件文件名
    const char* pluginAppName;  // 文本型：插件應用名
    const char* apiName;        // 文本型：此插件通過哪個API進行消息發送的,如:發送群消息
    const char* content;        // 文本型：消息內容
};

// 數據類型：群成員信息NT
struct GroupMemberInfoNT
{
    long long groupID;         // 長整數型：群號
    long long account;         // 長整數型：賬號
    const char* nickname;      // 文本型：暱稱
    const char* card;          // 文本型：群暱稱
    const char* sex;           // 文本型：性別
    int age;                   // 整數型：年齡
    const char* area;          // 文本型：地區
    long long joinTime;        // 長整數型：加群時間戳
    long long lastSpeakTime;   // 長整數型：最後發言時間戳
    int level;                 // 整數型：成員等級
    const char* role;          // 文本型：owner=群主，admin=管理員，member=群員
    const char* specialTitle;  // 文本型：專屬頭銜
    long long muteTime;        // 長整數型：禁言到期時間
};