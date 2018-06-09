// Auto-generated. Do not edit!

// (in-package bill_encoder.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Encoder {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.time_stamp = null;
      this.left_encoder_count = null;
      this.right_encoder_count = null;
    }
    else {
      if (initObj.hasOwnProperty('time_stamp')) {
        this.time_stamp = initObj.time_stamp
      }
      else {
        this.time_stamp = 0.0;
      }
      if (initObj.hasOwnProperty('left_encoder_count')) {
        this.left_encoder_count = initObj.left_encoder_count
      }
      else {
        this.left_encoder_count = 0;
      }
      if (initObj.hasOwnProperty('right_encoder_count')) {
        this.right_encoder_count = initObj.right_encoder_count
      }
      else {
        this.right_encoder_count = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Encoder
    // Serialize message field [time_stamp]
    bufferOffset = _serializer.float32(obj.time_stamp, buffer, bufferOffset);
    // Serialize message field [left_encoder_count]
    bufferOffset = _serializer.int64(obj.left_encoder_count, buffer, bufferOffset);
    // Serialize message field [right_encoder_count]
    bufferOffset = _serializer.int64(obj.right_encoder_count, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Encoder
    let len;
    let data = new Encoder(null);
    // Deserialize message field [time_stamp]
    data.time_stamp = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [left_encoder_count]
    data.left_encoder_count = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [right_encoder_count]
    data.right_encoder_count = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'bill_encoder/Encoder';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b66af2928dcdc45aac405392cc8c0f5c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 time_stamp
    int64 left_encoder_count
    int64 right_encoder_count
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Encoder(null);
    if (msg.time_stamp !== undefined) {
      resolved.time_stamp = msg.time_stamp;
    }
    else {
      resolved.time_stamp = 0.0
    }

    if (msg.left_encoder_count !== undefined) {
      resolved.left_encoder_count = msg.left_encoder_count;
    }
    else {
      resolved.left_encoder_count = 0
    }

    if (msg.right_encoder_count !== undefined) {
      resolved.right_encoder_count = msg.right_encoder_count;
    }
    else {
      resolved.right_encoder_count = 0
    }

    return resolved;
    }
};

module.exports = Encoder;
