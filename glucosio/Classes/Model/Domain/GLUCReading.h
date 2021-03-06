//
// Created by Chris Walters on 4/10/16.
// Copyright (c) 2016 Glucosio.org. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HealthKit/HealthKit.h>
#import "GLUCModel.h"
#import "UIColor+GLUCAdditions.h"
#import "GLUCUser.h"

@protocol RLMFloat;

static NSString *const kGLUCReadingNotesPropertyKey = @"notes";
static NSString *const kGLUCReadingModelValuePropertyKey = @"reading";

@interface GLUCReading : GLUCModel

+ (NSString *) menuIconName;
+ (UIColor *) readingColor;

+ (UIColor *) historyColor: (GLUCReading *) me forUser: (GLUCUser *) user;

// units = 0 is always the default units for the reading
- (NSNumber *) readingInUnits:(NSInteger)units;
+ (NSNumber *) convertValue:(NSNumber *)aValue fromUnits:(NSInteger)fromUnits toUnits:(NSInteger)toUnits;

- (NSDictionary *) dictionaryRepresentation;

+ (HKQuantityType *) healthKitQuantityType;

@property (nonatomic, readwrite, strong) NSNumber<RLMFloat> *reading;
@property (nonatomic, readwrite, strong) NSString *notes;
@end
