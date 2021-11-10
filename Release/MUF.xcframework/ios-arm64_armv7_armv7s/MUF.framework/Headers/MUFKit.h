//
//  MUFComponent.h
//  MUF
//
//  Created by zhengxq on 2018/6/11.
//  Copyright © 2018年 ChinaNetCenter. All rights reserved.
//


#import <netinet/in.h>
#import "MUFKitConfig.h"
#import <Foundation/Foundation.h>
#import "MUFLogLevel.h"


typedef int (*_OriginConnect)(int, const struct sockaddr *, socklen_t);
typedef void(^RecvMsgBlock)(NSString*);




@interface MUFKit : NSObject



- (instancetype)initWithConfiguration:(MUFKitConfig *)configer __attribute__((objc_requires_super));



/**
 recvMsg展开在里面可以接受到其他kit发来的消息
 */
@property (nonatomic, copy)RecvMsgBlock recvMsg;
/**
 *  发送消息/事件到其他组件消息;
 *  msgStrJson 相关参数(若不为空则以Json格式传参)
 */
- (void)sendMsg:(NSString *)msgJson __attribute__((objc_requires_super));


/**
 *  发送要上报的日志给muf进行上报;
 *  url 相关参数(日志上报的url)
 *  filePath 相关参数(日志的地址)
 *  type 相关参数（日志上报的类型）
 *  isNdk 相关参数 (日志是否来自ndk)
 *  isNeedDelete 相关参数 (日志添加到muf日志上报队列后是否要进行删除)
 */
- (BOOL)reportWithURL:(NSString *)url
             filePath:(NSString *)filePath
                 type:(NSString *)type
            isFromNdk:(BOOL)isNdk
         isNeedDelete:(BOOL)isNeedDelete __attribute__((objc_requires_super));


/**
 *  组件接收基础框架提供的原始connect指针。
 *  originConnect 原始的connect指针
 */
- (int)registOriginConnect: (_OriginConnect) originConnect;

///**
// * 当发生crash的时候，是否需要通知组件
// * 如果需要通知组件，组件获取到crash的通知后，需要发送消息给MUFCrashKit通知事情处理完成。
// */
//- (void)needNotificationWhenCrash:(BOOL)needNotice;


/**
 *  获取组件对应的配置信息
 *  返回值   组件对应的配置信息
 */
- (MUFKitConfig *)getConfiguration;

/**
 *  获取组件对应的版本信息
 *  组件需要重写该方法设置对应的版本信息
 *  返回值   组件对应的版本信息
 */
- (NSString *)kitVersion;



/**
 *  接受muf上报返回的结果 各kit子类自行实现;
 *  result 上报结果 key主要有code,其值为http响应码,code值为200是成功,其它值是失败
 *  para 上报内容除文件流之外其它字段信息
 */
- (void)onReportEnd:(NSDictionary *)result
               para:(NSDictionary *)para;
@end

