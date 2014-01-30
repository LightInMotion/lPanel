# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm
LOCAL_MODULE := juce_jni
LOCAL_SRC_FILES := \
  ../../../Source/AboutComponent.cpp\
  ../../../Source/PagePickerComponent.cpp\
  ../../../Source/lp-net.cpp\
  ../../../Source/LivePanelComponent.cpp\
  ../../../Source/MainWindow.cpp\
  ../../../Source/Main.cpp\
  ../../../JuceLibraryCode/BinaryData.cpp\
  ../../../JuceLibraryCode/modules/juce_core/juce_core.cpp\
  ../../../JuceLibraryCode/modules/juce_data_structures/juce_data_structures.cpp\
  ../../../JuceLibraryCode/modules/juce_events/juce_events.cpp\
  ../../../JuceLibraryCode/modules/juce_graphics/juce_graphics.cpp\
  ../../../JuceLibraryCode/modules/juce_gui_basics/juce_gui_basics.cpp\

ifeq ($(CONFIG),Debug)
  LOCAL_CPPFLAGS += -fsigned-char -fexceptions -frtti -g -I "../../JuceLibraryCode" -I "../../JuceLibraryCode/modules" -O0 -D "JUCE_ANDROID=1" -D "JUCE_ANDROID_API_VERSION=8" -D "JUCE_ANDROID_ACTIVITY_CLASSNAME=co_limsc_ipanel_iPanel" -D JUCE_ANDROID_ACTIVITY_CLASSPATH=\"co/limsc/ipanel/iPanel\" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_ANDROID_7F0E4A25=1" -D "JUCE_APP_VERSION=1.0.6" -D "JUCE_APP_VERSION_HEX=0x10006"
  LOCAL_LDLIBS := -llog -lGLESv2
  LOCAL_CFLAGS += -fsigned-char -fexceptions -frtti -g -I "../../JuceLibraryCode" -I "../../JuceLibraryCode/modules" -O0 -D "JUCE_ANDROID=1" -D "JUCE_ANDROID_API_VERSION=8" -D "JUCE_ANDROID_ACTIVITY_CLASSNAME=co_limsc_ipanel_iPanel" -D JUCE_ANDROID_ACTIVITY_CLASSPATH=\"co/limsc/ipanel/iPanel\" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_ANDROID_7F0E4A25=1" -D "JUCE_APP_VERSION=1.0.6" -D "JUCE_APP_VERSION_HEX=0x10006"
  LOCAL_LDLIBS := -llog -lGLESv2
else
  LOCAL_CPPFLAGS += -fsigned-char -fexceptions -frtti -I "../../JuceLibraryCode" -I "../../JuceLibraryCode/modules" -Os -D "JUCE_ANDROID=1" -D "JUCE_ANDROID_API_VERSION=8" -D "JUCE_ANDROID_ACTIVITY_CLASSNAME=co_limsc_ipanel_iPanel" -D JUCE_ANDROID_ACTIVITY_CLASSPATH=\"co/limsc/ipanel/iPanel\" -D "NDEBUG=1" -D "JUCER_ANDROID_7F0E4A25=1" -D "JUCE_APP_VERSION=1.0.6" -D "JUCE_APP_VERSION_HEX=0x10006"
  LOCAL_LDLIBS := -llog -lGLESv2
  LOCAL_CFLAGS += -fsigned-char -fexceptions -frtti -I "../../JuceLibraryCode" -I "../../JuceLibraryCode/modules" -Os -D "JUCE_ANDROID=1" -D "JUCE_ANDROID_API_VERSION=8" -D "JUCE_ANDROID_ACTIVITY_CLASSNAME=co_limsc_ipanel_iPanel" -D JUCE_ANDROID_ACTIVITY_CLASSPATH=\"co/limsc/ipanel/iPanel\" -D "NDEBUG=1" -D "JUCER_ANDROID_7F0E4A25=1" -D "JUCE_APP_VERSION=1.0.6" -D "JUCE_APP_VERSION_HEX=0x10006"
  LOCAL_LDLIBS := -llog -lGLESv2
endif

include $(BUILD_SHARED_LIBRARY)
