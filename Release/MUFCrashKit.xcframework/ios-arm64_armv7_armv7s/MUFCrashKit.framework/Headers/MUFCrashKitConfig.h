//
//  MUFCrashKitConfig.h
//  MUF
//
//  Created by zhengxq on 2018/11/6.
//  Copyright © 2018年 ChinaNetCenter. All rights reserved.
//

#import <MUF/MUFKitConfig.h>

@interface MUFCrashKitConfig : MUFKitConfig

/**
 *  设置崩溃日志的路径，该路径是根路径
 */
@property(nonatomic, retain) NSString *crashLogPath;  //crashLog路径   根目录

/**
 *  设置崩溃日志是否进行删除
 */
@property(nonatomic, assign) BOOL isDeleteLog;  //是否删除crash日志

/**
 * 崩溃轨迹最大采集数设置
 */
@property(nonatomic, assign) int crashTrackMaxCount;

@end
