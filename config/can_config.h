#pragma once

typedef enum CANID {

    // ERROR CAN IDs

    SAFETY_ERROR                = 0x100,
    ARM_ERROR,
    SCIENCE_ERROR,
    GIMBTONOMY_ERROR,

    // ARM CAN IDs

    RESET                       = 0x720,
    SET_OVERRIDE_FLAGS,

    SET_TURNTABLE_CONTROL_MODE  = 0x740,
    SET_SHOULDER_CONTROL_MODE,
    SET_ELBOW_CONTROL_MODE,
    SET_WRIST_CONTROL_MODE,
    SET_CLAW_CONTROL_MODE,

    SET_TURNTABLE_MOTIONDATA    = 0x745,
    SET_SHOULDER_MOTIONDATA,
    SET_ELBOW_MOTIONDATA,
    SET_WRIST_PITCH_MOTIONDATA,
    SET_WRIST_ROLL_MOTIONDATA,
    SET_CLAW_MOTIONDATA,
    SET_TOOL_TIP_DEPLOYMENT,

    RUN_WRIST_CALIBRATION       = 0x74C,
    RUN_CLAW_CALIBRATION,

    SET_PID_TUNING_MODE         = 0x750,
    SET_PID_DEADZONE,
    SET_JOINT_PID_P,
    SET_JOINT_PID_I,
    SET_JOINT_PID_D,
    SET_JOINT_PID_BIAS,

    REPORT_TURNTABLE_MOTION     = 0x758,
    REPORT_SHOULDER_MOTION,
    REPORT_ELBOW_MOTION,
    REPORT_WRIST_PITCH_MOTION,
    REPORT_WRIST_ROLL_MOTION,
    REPORT_CLAW_MOTION,
    FORCE_SENSOR_VALUE

} CANID;