//
//  MUFLog.h
//  MUF
//
//  Created by Sharezer on 2018/12/6.
//  Copyright © 2018 ChinaNetCenter. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MUFLogLevel.h"


NS_ASSUME_NONNULL_BEGIN

@interface MUFLog : NSObject

-(instancetype) initWithKit: (Class) kitClass level: (MUFLogLevel) level;
-(void) logVerbose: (NSString*)msg, ... NS_FORMAT_FUNCTION(1,2);
-(void) logInfo: (NSString*)msg, ... NS_FORMAT_FUNCTION(1,2);
-(void) logDebug: (NSString*)msg, ... NS_FORMAT_FUNCTION(1,2);
-(void) logWarning: (NSString*)msg, ... NS_FORMAT_FUNCTION(1,2);
-(void) logError: (NSString*)msg, ... NS_FORMAT_FUNCTION(1,2);
-(MUFLogLevel) getLevel;
-(void) setLevel: (MUFLogLevel)level;

@end

NS_ASSUME_NONNULL_END
