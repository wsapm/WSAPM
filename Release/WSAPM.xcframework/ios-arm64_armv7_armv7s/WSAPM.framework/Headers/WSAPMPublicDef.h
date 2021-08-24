//
//  WSAPMPublicDef.h
//  WSAPM
//
//  Created by wangsu on 2020/3/16.
//  Copyright © 2020 Wangsu. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum{
    kWSAPM_Event_Auth = 0,
    kWSAPM_Event_Req_Cfg = 1,
    kWSAPM_Event_Apply_Cfg = 2,
} WSAPMEvent;

typedef enum{
    kWSAPM_Ret_Success = 0,
    
    kWSAPM_Ret_Com_Net_Error = 1001,
    
    kWSAPM_Ret_Com_Auth_Error = 2001,
    kWSAPM_Ret_Com_Auth_ReAuth_Deny = 2002,
    
    kWSAPM_Ret_Req_Cfg_Fail = 3001,
    kWSAPM_Ret_Apply_Cfg_Fail = 3002,
} WSAPMRetCode;


#define kWSAPM_PRE_START_MODULE_NONE 0
#define kWSAPM_PRE_START_MODULE_WEBVIEW 1




@interface WSAPMPublicDef : NSObject

@end


