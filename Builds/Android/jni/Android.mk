# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := juce_jni
LOCAL_SRC_FILES := \
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
  LOCAL_CPPFLAGS += -fsigned-char -fexceptions -frtti -g -I "../../JuceLibraryCode" -O0 -D "JUCE_ANDROID=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_ANDROID_7F0E4A25=1"
else
  LOCAL_CPPFLAGS += -fsigned-char -fexceptions -frtti -I "../../JuceLibraryCode" -Os -D "JUCE_ANDROID=1" -D "NDEBUG=1" -D "JUCER_ANDROID_7F0E4A25=1"
endif

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2

include $(BUILD_SHARED_LIBRARY)
