//
//  XPCLoadTest.m
//  GPGMail
//
//  Created by Lukas Pitschl on 14.01.15.
//
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <Libmacgpg/Libmacgpg.h>

@interface XPCLoadTest : XCTestCase

@end

@implementation XPCLoadTest

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testDecryption {
    // This is an example of a functional test case.
    [[GPGKeyManager sharedInstance] allKeys];
    NSString *message = @"-----BEGIN PGP MESSAGE-----\n\
Comment: GPGTools - https://gpgtools.org\n\
\n\
hQEMA1QW4UmvSHTqAQgA1NHJoECrNsbmZYQdNM7ThAajcXGtSV7Sat/9AIg4w5Do\n\
JryWMn6SwX6firbaiFiIQRygaRiv39Yf+kC98ogiSvskX6AAYU5zzkEzpf1A7KFq\n\
CljKkSzgOQDHD+fhB5Jb5Bhr8fTkhcIATQy11NUvthuVnZxMLxYPEF4OTLiYsm2C\n\
HUwnp5dhQIz39CewYd2yxlrdwQ+bZ1/ewfII8Tr7ONlB/WeTqTOtiScDTl1iyqro\n\
X0pswY2SLDJDIEMsFHKgkDFK3WSuG2xSaBsNrdg+LflQebMPpNFT9X0p9mcMAemX\n\
YBZPulP9a2f6YOelPkoTLmiytphhuo0nkw64W04zfYUCDgPo4gMIANXtlhAH/iE3\n\
QGx9ZSmeH0zf6C+f/QYhb57V/i9mSG9C/Hp31BBFK4v1Nw3oe7yPcUGpGztF621y\n\
YJq7lUbHCvS7MFInoDBUcuyBOOjBVn5cXkQooxOUyxmbgkXAsQHm7Kti+ntxLJAz\n\
mbzpEXnXctRFTzwPgk+AuFtWbgHyPO3CyGyoqffVwIdk0BOVVsv08bjLGvEsyFYq\n\
lEJ6+2j1biOy65XWExNIgsv17eLbxRFgD4Xbnz722M7aRh/6LftCE5XETjYf26EJ\n\
FgMNwNQPLJb+r9mpF4SBHKS2wbLBtSiXhd3lI+RmWwy+mqcFRZVqHLRRXXVLOIHJ\n\
XIqaU+Lv4yvChlA0MDgH/jbYDn9ZWQ9xSvNdUteG7rNluXcxpHTEHA1lYvHkYpHh\n\
3bUVciwuMZLDxz4kWn8gnnhI1azeHyOmhzChXSgs9tOTsCd/njv6KIASSKcI+fhq\n\
gGu/0FTVTGsmdJ5Yyb4l9sidOwyK9s8MW8lg6WZI1XrjEbft3dp0RCoXCNOxydnH\n\
oNck3+YExzk4AnNbDZtjwrVtWJ4sMd8DGhWG6jTYib75QvIYG5i5HSDKKWJfh/0M\n\
Adxef29GcgOFvFcuiDI8KlOsV3bolnJQxa5+dMAANWe6kAresE/ncaUqwrKpv58+\n\
bM5hpeax36/4SrjNEwiQeGHcSukSTWl7lH+jhULH77yFAgwD4t7f+4DBRYQBD/oC\n\
03sAVRC88rwiKCWUPlwqi0CkPn0ubipNwh/eKKVO+c/U+BkHhtFGD8BPCziYP3xF\n\
KgL4B8nBbK6V8BXepdHgSIH1wkDvpXYSYCgjziG36mpn9eCE+Fq38gBHIDCFx7pJ\n\
K4HEQ+ZyQzHZeLOOEitxvo9IA3MsTVzSSDCK/A8fYsqo8Ukjk9K1068sKiY1N+ua\n\
ZEbt3meiEmc6rSUABA61N9MjRBy1edgC0t5YcMkekU/OSp0fN/REqMUOUWCwgvLe\n\
PtuziM+7lKNsQ4cO4M62Pjer+/gFhsa41HtAbti08b3rbGaU8UgV5iha/iWjfFRL\n\
6h5VQFJtayHRzuyB9vR2w1MyT92RWehf+Hmp1cCNDxM2AIMV93eUy5vEK0wOaqzT\n\
uRO/5JfzbrSghoSWov273NzaWV4SGxBctQQw4JXqe4Cgv+bbgestgztDIi7dWID1\n\
xWZ/K/iAWU92yJg2j7eSu+Jrj+/r1QqFyKLBrqLtp/lblc2YaPVlEb6TdUGAG4Uw\n\
avIzdRXghJvhYPAhdTyBmp2MAgA2TMyI68NbNnKez1FEolmOAL8Wp4rR7W0o1wBz\n\
xcvE64ESRTDLvGVzq82nLNiDBCs3y7vsg3sPVf+399b3lTvulpt/O0wICH1wD8ir\n\
n3TG/QuKs/4wGosaoDL+2i4UPK9Oc/Wmrvh8g3Z8oYUBDANMeGGd6/lAdwEH/16e\n\
lk4lZsN934VhlfXJVUgzWBxFwhdBFxwjjeh9qxHwe9NSktw4kv6DXCX6XQTmfp8s\n\
kZOBFVX7ziZ/gZOBZad9nQEAIMh3L18h99kuFtg2586CURJIsOrTsnJuJy4SGpyN\n\
HD79OLRDFp6PL6hXD1dlkzeUI8MXh81+zD8pygD1tw5Fe+Vg8RIYUApr6pGD4dhm\n\
IFoT0U0S3QfwBh61aQFOGobsRXilSY7rmriZNSwyXu58J9xbcEuSaXLGSRzUzR2P\n\
cgWwjg56orm5zWCnFQCPJJkD+w1wmOajoa1JGYLOS3mZO2OH4xBIx0KMivrgXBJr\n\
AvTOvz8gQ8Y6mQiSuJeFAg4DuKa3TAAYksIQB/wPRfNB/TR7sEAy+AMi23/VNsvg\n\
toGMw7mXJaZvk0p/Pj8RBJ0/4d3lUan/fOB78Z33EIw73Ml48xtuldkYDDUXJRXU\n\
lfY04iNjv9+wFP8Mty3ZuOs45x94iiHyMqIWqcbDmG0mfUmgETQ/6H755Jba8TTD\n\
ShHOdLfvNuUfsvEzdWtT2DbyBGbyLw1bX1hTgwuvjyukoG5w3yVs7wwI8+DhmC5s\n\
L6pjRCz5Ktlsb98ehsESef/9+BzRObob8qBvhNNIaOZuTUsWm+G7tNG4sH9+vmSw\n\
fMm0vy+R3GVcqztvVc/zTsXrwGG7zgS+uPkE4on5jJ+KV7s+oBPidbH+pY8yB/wN\n\
WMUpax32swKqY07VRgVCFLFSNt9hAOFsRPr/dr+vq/3Td3VpbB/pHcseKnmdJoTy\n\
E8l/D9tmGfbdZiXccXN5zi05dQ+SW/eB7FyPDPmPpq23QchrxNFgontFg5VzUgf7\n\
S5R3McQ3pGDdjVwRnXDuQQI30UpfiNo1ZGmiRK5rqYOe7omdxmNKFWXZO761wwKc\n\
wsAQMMGq3NcfX5tASUrauhsJseaCGpSDOvXDcQxtNk2OkscJXdDE1nrLwRYDldpK\n\
rqI2rtkIBZKYhPKDpfUUlyorCbLNmhUqEnKUW50zR68NtVaMRYHJY9DcrRjBnxSX\n\
EpvTgutIs4ZDN5oNBnZu0rMBZLML+zw7jGMJsOD56UaxO3er2IfA1Y3x8xVGdkC4\n\
PxdNRi+VpaD5huFNo6hgtVw3AAwTaK9hcyp5gNsfZ9+KFIlSH+s45NO+oQUlG6ot\n\
yOdUoenPzPoMOw/rhhDsISGkQ6yVDLxD0A8grGdLurXKF1TXgm6ishBc+l/ZbTvf\n\
j066OCdmNGUs5104Av+z+ah/77eJr9JPBEguTrXBX/DvIYSZI0iZMG1D/V56gRtF\n\
8HutJA==\n\
=o5tC\n\
-----END PGP MESSAGE-----\n";
    NSData *messageData = [message dataUsingEncoding:NSUTF8StringEncoding];
    
    // Let's run 100 threads at a time and see what happens.
    //dispatch_queue_t loadTestQueue = dispatch_queue_create("org.gpgtools.gpgmail.loadTest", DISPATCH_QUEUE_CONCURRENT);
    //dispatch_semaphore_t block = dispatch_semaphore_create(100);
    
    dispatch_apply(70, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(size_t index) {
        NSLog(@"[%zu] decryption task start", index);
        GPGController *controller = [[GPGController alloc] init];
        NSData *decryptedData = [controller decryptData:messageData];
        NSString *decryptedString = [[NSString alloc] initWithData:decryptedData encoding:NSUTF8StringEncoding];
        NSString *verificationString = @"This is a test";
        //dispatch_semaphore_signal(block);
        NSLog(@"[%zu] decryption task completed", index);
        XCTAssert([decryptedString isEqualToString:verificationString], @"Pass");
    });
    
    //dispatch_semaphore_wait(block, DISPATCH_TIME_FOREVER);
}

- (void)testVerification {
    // This is an example of a functional test case.
    [[GPGKeyManager sharedInstance] allKeys];
    NSData *data = [NSData dataWithContentsOfFile:@"/Users/lukele/Downloads/GPGMail-2.5b4.dmg"];
//    NSData *verification = [NSData dataWithContentsOfFile:@"/Users/lukele/Downloads/GPGMail-2.5b4.dmg.sig"];
    
//    NSData *data = [NSData dataWithContentsOfFile:@"/Users/lukele/Downloads/Episodes.S04E01.HDTV.x264-ASAP.mp4"];
    
    // Let's run 100 threads at a time and see what happens.
    //dispatch_queue_t loadTestQueue = dispatch_queue_create("org.gpgtools.gpgmail.loadTest", DISPATCH_QUEUE_CONCURRENT);
    //dispatch_semaphore_t block = dispatch_semaphore_create(100);
    
    for(int i = 0; i < 1; i++) {
        dispatch_apply(1, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(size_t index) {
            GPGController *controller = [[GPGController alloc] init];
            NSLog(@"[%zu] Verification task start", index);
//            NSData *signedData = [controller processData:data withEncryptSignMode:GPGSign recipients:nil hiddenRecipients:nil];
//            if(!signedData)
//                XCTAssert(signedData != nil, @"Failed to sign data.");
            
            controller = [[GPGController alloc] init];
            NSData *encryptedData = [controller processData:data withEncryptSignMode:GPGEncryptSign recipients:@[@"lukele@gpgtools.org"] hiddenRecipients:nil];
            if(!encryptedData) {
                XCTAssert(encryptedData != nil, @"Failed to encrypt and sign data");
            }
            
//            controller = [[GPGController alloc] init];
//            NSData *decryptedData = [controller decryptData:encryptedData];
//            if(!decryptedData) {
//                XCTAssert([decryptedData isEqual:data], @"Failed to decrypt data");
//            }
//            
//            controller = [[GPGController alloc] init];
//            NSArray *signatures = [controller verifySignedData:decryptedData];
//            XCTAssert([controller.signatures count] == 1, @"Failed to verify decrypted data.");
//            if([controller.signatures count] != 1) {
//                NSLog(@"[%zu] Failed!", index);
//            }
            NSLog(@"[%zu] verification task completed", index);
        });
    }
    
    
    //dispatch_semaphore_wait(block, DISPATCH_TIME_FOREVER);
}


- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
