//
//  WSAPM.h
//  WSAPM
//
//  Created by wangsu on 2020/3/16.
//  Copyright © 2020 Wangsu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WSAPMPublicDef.h"
@protocol WSAPMDelegate <NSObject>

/**
回调SDK内部相关事件  相关定义详见WSAPMPublicDef.h
@param eventId 事件ID
@param extra 事件详情
*/
- (void)onWSAPMEvent:(NSInteger)eventId extra:(NSDictionary *_Nullable)extra;

@end




@interface WSAPM : NSObject {
    
}
@property (nonatomic, assign) id <WSAPMDelegate> _Nullable delegate;

/**
预启动模块设置 默认为0  目前可支持 kWSAPM_PRE_START_MODULE_WEBVIEW  即预启动WKWebview模块的功能。
重要：该配置应该在调用start接口之前设置。
*/
@property (nonatomic) NSInteger preStartModules;

/**信任无效或过期SSL证书服务器的域名组.
 * 例如：ignoreServerCerAuthArray = [[NSArray alloc] initWithObjects:@"www.baidu.com",@"www.baidu2.com", nil];
 */
@property (nonatomic, strong) NSArray * _Nullable ignoreServerCerAuthArray;

- (instancetype _Nullable )init NS_UNAVAILABLE;


/**
 初始化WSAPM对象传入appKey appSecret, 全局只能调用一次
 @param appKey 网宿公司分配的appKey
 @param appSecret 网宿公司分配的appSecret
 @return WSAPM对象
 */
+ (WSAPM *_Nullable)create:(NSString *_Nonnull)appKey appSecret:(NSString *_Nullable)appSecret;

/**
 启动WSAPM的相关功能  使用create:appSecret:接口返回的WSAPM对象调用此接口,在调用start之前可设置delegate以监听SDK相关事件
 */
- (void)start;

/**
 关闭WSAPM的相关功能  使用create:appSecret:接口返回的WSAPM对象调用此接口
*/
- (void)stop;

/**
 获取SDK的版本号
 @return SDK的版本号
*/
+ (NSString *_Nullable)getVersion;


/**
 获取app对应的设备唯一ID
 @return 唯一ID
*/
+ (NSString *_Nullable)getUuid;

/**
 *   用户调用进行手动网络检测，弹出默认检测分析界面。
 *   @return YES启动成功, NO启动失败
 */
+ (BOOL)doManualDiagnosis;

/**
 *   用户调用进行手动网络检测，弹出默认检测分析界面，用户可以在回调中对VC进行一些UI制定
 *   控制push还是present这个VC
 *
 *  @param customAction 用户回调
 *  @return YES启动成功, NO启动失败
 */
+ (BOOL)doManualDiagnoseWithCustomAction:
(void (^_Nullable)(UIViewController * _Nullable viewController))customAction;

/**
 *   用户调用进行自动配置网络检测，不会弹出分析界面。后台检测，检测完成后日志上报到APM服务器进行分析。
 */
+ (BOOL)doAutoDiagnosis;

/**
 *  为了便于问题追踪，APP可以设置customId，该字段在相应的性能报文中有所体现。
 *  长度可支持256个字符
 *
 *  @return 设置是否成功
 */
+ (BOOL)setCustomId:(nullable NSString *)value;


/**
 *  为了便于问题追踪，APP可以设置customInfo，该字段在相应的性能报文中有所体现。
 *  长度可支持1024个字符
 *
 *  @return 设置是否成功
 */
+ (BOOL)setCustomInfo:(nullable NSString *)value;


/**
 *  设置NSURLSession复用是否开启 默认关闭
 *
 */
+ (void)setURLSessionReuse:(BOOL)enable;

/**
 *  自定义事件监听
 *  @param eventID 事件标识、检索，最多32位，但不能包含空格或其他的转义字符
 *  @param eventTag 分类，最大长度限制为 256字符，超出截取
 *  @param eventProperties 最多配置64个键值（超出后设置的随机丢弃），key（String，最大长度限制为
 *  256字符，超出截取，为空丢弃），value（支持Number，String类型，可以为nil、null，长度不能超过4096字符，超出截取），nil、null转为空字符串
 *  @return 设置是否成功
 *
 */
+ (BOOL)monitorEvent:(NSString *_Nonnull)eventID withEventTag:(NSString *_Nullable)eventTag withEventProperties:(NSDictionary *_Nullable)eventProperties;

/**
 *  不存在异常堆栈的自定义异常监听
 *  @param message 消息 ， 不可以传空，空返回异常，最大长度1024字符，超出截取前1024字符
 *  @param metaData 元数据，最多配置64个键值（超出后设置的部分随机丢弃），key（String，最大长度限制为
 *  256字符，超出截取，为空或则存在其他转义字符丢弃），value（支持Number，String类型，可以为nil、null，长度不能超过4096字符，超出截取），nil、null转为空字符串
 *  @return 设置是否成功
 *
 */
+ (BOOL)monitorError:(NSString *_Nonnull)message withMetaData:(NSDictionary *_Nullable)metaData;

/**
 *  存在异常堆栈的自定义异常监听
 *  @param message 消息 ， 不可以传空，空返回异常，最大长度1024字符，超出截取前1024字符
 *  @param exception 异常
 *  @param metaData 元数据，最多配置64个键值（超出后设置的部分随机丢弃），key（String，最大长度限制为
 *  256字符，超出截取，为空或则存在其他转义字符丢弃），value（支持Number，String类型，可以为nil、null，长度不能超过4096字符，超出截取），nil、null转为空字符串
 *  @return 设置是否成功
 *
 */
+ (BOOL)monitorError:(NSString *_Nonnull)message withException:(NSException *_Nullable)exception withMetaData:(NSDictionary *_Nullable)metaData;




@end


