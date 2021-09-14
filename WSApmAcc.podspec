#
# Be sure to run `pod lib lint MSocketRocket.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'WSApmAcc'
  s.version          = '2.4.1'
  s.summary          = 'Wangsu APM + ACC'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
Wangsu APM + ACC SDK
                       DESC

  s.homepage         = 'https://www.wangsu.com'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'wsapm' => 'vpclient_coop@wangsu.com' }
  s.source           = { :git => 'https://github.com/wsapm/WSAPM.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'
  
  s.vendored_frameworks = "Release/MUF.xcframework", "Release/WSAPM.xcframework", "Release/WSAPMAcc.xcframework", "Release/MUFCrashKit.xcframework"
  s.resource = "Release/WSAPM.bundle"
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'arm64 armv7 x86_64' }
  
  # s.resource_bundles = {
  #   'MSocketRocket' => ['MSocketRocket/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
