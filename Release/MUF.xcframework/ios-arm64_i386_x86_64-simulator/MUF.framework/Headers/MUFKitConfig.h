//
//  MUFCompConfiguration.h
//  MUF
//
//  Created by zhengxq on 2018/6/11.
//  Copyright © 2018年 ChinaNetCenter. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MUFKitConfig : NSObject

/**
 *  获取组件对应的类名
 *  组件需要重写该方法设置对应的类名
 *  返回值   组件对应的类名
 */
- (NSString *)kitClass;

/**
 *  获取组件对应的组件标识
 *  组件需要重写该方法设置对应的组件标识
 *  返回值   组件对应的组件标识
 */
- (NSString *)kitIdentify;


@end

