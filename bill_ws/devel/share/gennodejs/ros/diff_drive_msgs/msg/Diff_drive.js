// Auto-generated. Do not edit!

// (in-package diff_drive_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Diff_drive {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.time_stamp = null;
      this.left_wheel_vel = null;
      this.right_wheel_vel = null;
    }
    else {
      if (initObj.hasOwnProperty('time_stamp')) {
        this.time_stamp = initObj.time_stamp
      }
      else {
        this.time_stamp = 0.0;
      }
      if (initObj.hasOwnProperty('left_wheel_vel')) {
        this.left_wheel_vel = initObj.left_wheel_vel
      }
      else {
        this.left_wheel_vel = 0.0;
      }
      if (initObj.hasOwnProperty('right_wheel_vel')) {
        this.right_wheel_vel = initObj.right_wheel_vel
      }
      else {
        this.right_wheel_vel = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Diff_drive
    // Serialize message field [time_stamp]
    bufferOffset = _serializer.float32(obj.time_stamp, buffer, bufferOffset);
    // Serialize message field [left_wheel_vel]
    bufferOffset = _serializer.float32(obj.left_wheel_vel, buffer, bufferOffset);
    // Serialize message field [right_wheel_vel]
    bufferOffset = _serializer.float32(obj.right_wheel_vel, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Diff_drive
    let len;
    let data = new Diff_drive(null);
    // Deserialize message field [time_stamp]
    data.time_stamp = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [left_wheel_vel]
    data.left_wheel_vel = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [right_wheel_vel]
    data.right_wheel_vel = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'diff_drive_msgs/Diff_drive';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0203216223fb8c1d3e2b8b595642daed';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 time_stamp
    float32 left_wheel_vel
    float32 right_wheel_vel
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Diff_drive(null);
    if (msg.time_stamp !== undefined) {
      resolved.time_stamp = msg.time_stamp;
    }
    else {
      resolved.time_stamp = 0.0
    }

    if (msg.left_wheel_vel !== undefined) {
      resolved.left_wheel_vel = msg.left_wheel_vel;
    }
    else {
      resolved.left_wheel_vel = 0.0
    }

    if (msg.right_wheel_vel !== undefined) {
      resolved.right_wheel_vel = msg.right_wheel_vel;
    }
    else {
      resolved.right_wheel_vel = 0.0
    }

    return resolved;
    }
};

module.exports = Diff_drive;
