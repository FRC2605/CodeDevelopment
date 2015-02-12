LARUL
=====
Liam's Advanced Robotics Utility Library
----------------------------------------

LARUL Is a C++ class library similar to WPILib designed to be an easy-to-use, powerful, and highly runtime-configurable abtraction to robot software design. It consists of many wrappers to cleanly encapsulate other libraries, controllers to delegate and manage software and hardware components, and both software and hardware abstration layers to generalize system design. It is designed with Usability, Robustness, and Utility in mind, with the goal of performing favorably for future FRC Robotics seasons.

Current Features
----------------
- Thread safety throughout where deemed practical.
- Behavioral state machine, allowing for multiple simultaneous states.
- Persistant robot-local configuration. (Wrapping the Jansson json library)
- Unified, prioritized logging and error interface.
- Synchronously scheduled asynchronous event loop.
- Custom optimized and caching allocation schemes.
- Cleanly wrapped TCP networking.
- Cleanly wrapped UDP networking.
- Fully featured POSIX Thread library wrapper.
- Asynchronous message queue with timing utilities
- Arbitrary address locking mechanism.
- Powerful delegate and method closure system.

Partial Features
----------------
- Driver station input wrappers for HID control processing.
- DSP interface and filters.
- Mathematic utility library
- Sensor HAL.
- Motion HAL.
- 2D/3D Mathematics utilities.

Planned Features
----------------
- Whatever else I feel like at any point in time...
- IMU/Inertial navigation utilities.

Tentatively Planned Features
----------------------------
- Possible python scripting utility wrapping CPython.
- We just don't know

