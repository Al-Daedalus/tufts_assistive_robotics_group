; Auto-generated. Do not edit!


(cl:in-package encoder_msgs-msg)


;//! \htmlinclude Encoder.msg.html

(cl:defclass <Encoder> (roslisp-msg-protocol:ros-message)
  ((time_stamp
    :reader time_stamp
    :initarg :time_stamp
    :type cl:float
    :initform 0.0)
   (left_encoder_count
    :reader left_encoder_count
    :initarg :left_encoder_count
    :type cl:integer
    :initform 0)
   (right_encoder_count
    :reader right_encoder_count
    :initarg :right_encoder_count
    :type cl:integer
    :initform 0))
)

(cl:defclass Encoder (<Encoder>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Encoder>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Encoder)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name encoder_msgs-msg:<Encoder> is deprecated: use encoder_msgs-msg:Encoder instead.")))

(cl:ensure-generic-function 'time_stamp-val :lambda-list '(m))
(cl:defmethod time_stamp-val ((m <Encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader encoder_msgs-msg:time_stamp-val is deprecated.  Use encoder_msgs-msg:time_stamp instead.")
  (time_stamp m))

(cl:ensure-generic-function 'left_encoder_count-val :lambda-list '(m))
(cl:defmethod left_encoder_count-val ((m <Encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader encoder_msgs-msg:left_encoder_count-val is deprecated.  Use encoder_msgs-msg:left_encoder_count instead.")
  (left_encoder_count m))

(cl:ensure-generic-function 'right_encoder_count-val :lambda-list '(m))
(cl:defmethod right_encoder_count-val ((m <Encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader encoder_msgs-msg:right_encoder_count-val is deprecated.  Use encoder_msgs-msg:right_encoder_count instead.")
  (right_encoder_count m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Encoder>) ostream)
  "Serializes a message object of type '<Encoder>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'time_stamp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'left_encoder_count)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'right_encoder_count)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Encoder>) istream)
  "Deserializes a message object of type '<Encoder>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time_stamp) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'left_encoder_count) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'right_encoder_count) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Encoder>)))
  "Returns string type for a message object of type '<Encoder>"
  "encoder_msgs/Encoder")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Encoder)))
  "Returns string type for a message object of type 'Encoder"
  "encoder_msgs/Encoder")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Encoder>)))
  "Returns md5sum for a message object of type '<Encoder>"
  "b66af2928dcdc45aac405392cc8c0f5c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Encoder)))
  "Returns md5sum for a message object of type 'Encoder"
  "b66af2928dcdc45aac405392cc8c0f5c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Encoder>)))
  "Returns full string definition for message of type '<Encoder>"
  (cl:format cl:nil "float32 time_stamp~%int64 left_encoder_count~%int64 right_encoder_count~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Encoder)))
  "Returns full string definition for message of type 'Encoder"
  (cl:format cl:nil "float32 time_stamp~%int64 left_encoder_count~%int64 right_encoder_count~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Encoder>))
  (cl:+ 0
     4
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Encoder>))
  "Converts a ROS message object to a list"
  (cl:list 'Encoder
    (cl:cons ':time_stamp (time_stamp msg))
    (cl:cons ':left_encoder_count (left_encoder_count msg))
    (cl:cons ':right_encoder_count (right_encoder_count msg))
))
