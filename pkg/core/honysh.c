#include <Carbon/Carbon.h>
#include <stdio.h>
#include <string.h>

void resize(pid_t pid, float x, float y, float w, float h) {

  AXValueRef tmp;

  CGSize windowSize;
  CGPoint windowPos;

  AXUIElementRef topApp;
  AXUIElementRef topWindow;

  topApp = AXUIElementCreateApplication(pid);
  AXUIElementCopyAttributeValue(topApp, kAXFocusedWindowAttribute,
                                (CFTypeRef *)&topWindow);
  CFRelease(topApp);

  AXUIElementCopyAttributeValue(topWindow, kAXSizeAttribute, (CFTypeRef *)&tmp);
  AXValueGetValue(tmp, kAXValueCGSizeType, &windowSize);
  CFRelease(tmp);

  AXUIElementCopyAttributeValue(topWindow, kAXPositionAttribute,
                                (CFTypeRef *)&tmp);
  AXValueGetValue(tmp, kAXValueCGPointType, &windowPos);
  CFRelease(tmp);

  windowPos.x = x;
  windowPos.y = y;
  windowSize.width = w;
  windowSize.height = h;

  tmp = AXValueCreate(kAXValueCGPointType, &windowPos);
  AXUIElementSetAttributeValue(topWindow, kAXPositionAttribute, tmp);
  CFRelease(tmp);

  tmp = AXValueCreate(kAXValueCGSizeType, &windowSize);
  AXUIElementSetAttributeValue(topWindow, kAXSizeAttribute, tmp);
  CFRelease(tmp);

  CFRelease(topWindow);
}