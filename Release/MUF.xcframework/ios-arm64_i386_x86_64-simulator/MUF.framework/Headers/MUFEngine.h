//
//  MUFEngine.h
//  MUF
//
//  Created by zhengxq on 2018/6/11.
//  Copyright © 2018年 ChinaNetCenter. All rights reserved.
//


#import <netinet/in.h>
#import "MUFKitConfig.h"
#import "MUFKit.h"




@interface MUFEngine : NSObject

/**
 *  设置应用的appKey和appSecret
 *  
 *  @param appKey 平台分配给对应应用的appKey
 *  @param appSecret 平台分配给对应应用的appSecret
 *
 */
+ (void)setAppKey:(NSString *)appKey appSecret:(NSString *)appSecret;



/**
 *  注册组件
 *  一个组件组件类名。需要多个组件可以调用多次，同一个组件只需要调用一次
 *  @param kitClass 组件对应的类名
 *  @param config 组件对应所需要的参数实例,可为nil
 *
 *  @return 返回值 0指示组件注册成功 返回值-1指示组件创建失败  返回值-2指示组件已经注册过  
 */
+ (int)registKit:(Class) kitClass withConfiger:(MUFKitConfig *)config;

/**
 *  获取相应组件实例
 *
 *  @param kitClass 组件对应的类名
 *
 *
 *  @return 返回相应组件实例
 */
+ (MUFKit *)getKit:(Class) kitClass;

/**
 *  获取所有组件名字
 *
 *
 *
 *  @return 返回所有组件名字组
 */
+ (NSArray *)getKitNameList;

/**
 *  获取MUF框架的日志等级
 *
 *  该返回值为MUF框架的日志等级，MUF日志等级受MUP控制，如果对应组件也想受MUP控制
 *  可以等鉴权成功后，重新获取这个值，进行重新设置。
 *
 *  @return 返回MUF框架的日志等级
 */
+ (MUFLogLevel)getLogLevel;


/**
*  获取注册所有kit名称以及对应的版本号
*
*  @return该返回值为注册所有kit名称以及对应的版本号。格式为Kit1:Version1,Kit2:Version2.
*
*/
+ (NSString *)kitArray;

/**
*  muf 启动时间
*
*  @return该返回值为muf 启动时间
*
*/
+ (NSTimeInterval)startTimestamp;


@end

