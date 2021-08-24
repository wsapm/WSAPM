//
//  WSAPMAcc.h
//  WSAPMAcc
//
//  Created by ws-82004303 on 2020/12/14.
//

#import <Foundation/Foundation.h>
#import "WSAccMonitoringInfo.h"
#import <MUF/MUFLog.h>
#import "AccNDKConfig.h"

// 导流关闭原因
typedef NS_ENUM(NSInteger, ACCProxyState){
    ACCHttpAndWebsocketProxySuccess,   // 正常导流
    ACCOnlyHttpProxySuccess,   // http正常导流
    ACCOnlyWebsocketProxySuccess,   // http正常导流
    ACCProxyFailedForBackground, //退到后台不导流
    ACCProxyFailedForManualClose, // 用户关闭了导流
    ACCProxyFailedForNDKFailedNeedRepDeb, // ndk启动失败，或则ndk中途启动失败。需要上报debug日志
    ACCProxyFailedForNDKFailed, // ndk启动失败，或则ndk中途启动失败。不需要上报debug日志
};


typedef enum {
    ACCNotReachable = 0,                         // 没有网络
    ACCReachableUnknow = 1,                      // 未知网络
    ACCReachableViaWiFi = 2,                     // WiFi网络
    ACCReachableVia2G = 3,                       // 2G网络
    ACCReachableVia3G = 4,                       // 3G网络
    ACCReachableVia4G = 5,                       // 4G网络
    ACCReachableVia5G = 6,                       // 5G网络
    ACCReachableCount                            // 网络状态个数
} ACCNetworkState;

@protocol WSAPMAccDelegate <NSObject>

/// WSPX 代理状态变化回调接口（该接口回调会在主线程执行）
/// @param proxyState  导流状态 备注：当导流关闭或则失败的情况下，proxyIp为nil，proxyPort为0
/// @param proxyIp 导流服务IP 一般是 127.0.0.1
/// @param proxyPort 导流服务 https 端口 （代理模式）
- (void)AccProxyEnable:(ACCProxyState)proxyState
               proxyIp:(NSString *)proxyIp
         httpProxyPort:(int32_t)proxyPort
    websocketProxyPort:(int32_t)wsProxyPort;
             

@end

@interface WSAPMAccConfigInfo : NSObject

@property (nonatomic, strong) AccNDKConfig *ndkConfig;//ndk配置
@property (nonatomic, strong) NSString *userId;  //userID
@property (nonatomic, assign) ACCNetworkState netState;
@property (nonatomic, strong) MUFLog *apmLog;
@property (nonatomic, assign) BOOL openWebSocket;
@property (nonatomic, strong) NSString *accFilePath;

@end

@interface  WSAPMAcc : NSObject

+ (BOOL)startACCWithConfig:(WSAPMAccConfigInfo *)config
                  delegate:(id<WSAPMAccDelegate>) delegate
                     queue:(dispatch_queue_t)queue;

+ (void)updateConfig:(WSAPMAccConfigInfo *)config;
+ (void)updateNetwork:(ACCNetworkState)netstate;
+ (WSAccMonitoringInfo *)monitoringInfor:(NSString *)host;

+ (void)updateDispacthInfo:(NSDictionary *)d;

+ (NSString *)authString:(NSString *)url;

+ (void)stopACC;
+ (void)restartACC;

+ (NSString *)sdkVersion;


@end





