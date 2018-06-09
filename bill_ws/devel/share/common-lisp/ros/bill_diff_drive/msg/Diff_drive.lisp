; Auto-generated. Do not edit!


(cl:in-package bill_diff_drive-msg)


;//! \htmlinclude Diff_drive.msg.html

(cl:defclass <Diff_drive> (roslisp-msg-protocol:ros-message)
  ((time_stamp
    :reader time_stamp
    :initarg :time_stamp
    :type cl:float
    :initform 0.0)
   (left_wheel_vel
    :reader left_wheel_vel
    :initarg :left_wheel_vel
    :type cl:float
    :initform 0.0)
   (right_wheel_vel
    :reader right_wheel_vel
    :initarg :right_wheel_vel
    :type cl:float
    :initform 0.0))
)

(cl:defclass Diff_drive (<Diff_drive>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Diff_drive>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Diff_drive)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name bill_diff_drive-msg:<Diff_drive> is deprecated: use bill_diff_drive-msg:Diff_drive instead.")))

(cl:ensure-generic-function 'time_stamp-val :lambda-list '(m))
(cl:defmethod time_stamp-val ((m <Diff_drive>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bill_diff_drive-msg:time_stamp-val is deprecated.  Use bill_diff_drive-msg:time_stamp instead.")
  (time_stamp m))

(cl:ensure-generic-function 'left_wheel_vel-val :lambda-list '(m))
(cl:defmethod left_wheel_vel-val ((m <Diff_drive>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bill_diff_drive-msg:left_wheel_vel-val is deprecated.  Use bill_diff_drive-msg:left_wheel_vel instead.")
  (left_wheel_vel m))

(cl:ensure-generic-function 'right_wheel_vel-val :lambda-list '(m))
(cl:defmethod right_wheel_vel-val ((m <Diff_drive>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bill_diff_drive-msg:right_wheel_vel-val is deprecated.  Use bill_diff_drive-msg:right_wheel_vel instead.")
  (right_wheel_vel m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Diff_drive>) ostream)
  "Serializes a message object of type '<Diff_drive>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'time_stamp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'left_wheel_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'right_wheel_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Diff_drive>) istream)
  "Deserializes a message object of type '<Diff_drive>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time_stamp) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_wheel_vel) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_wheel_vel) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Diff_drive>)))
  "Returns string type for a message object of type '<Diff_drive>"
  "bill_diff_drive/Diff_drive")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Diff_drive)))
  "Returns string type for a message object of type 'Diff_drive"
  "bill_diff_drive/Diff_drive")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Diff_drive>)))
  "Returns md5sum for a message object of type '<Diff_drive>"
  "0203216223fb8c1d3e2b8b595642daed")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Diff_drive)))
  "Returns md5sum for a message object of type 'Diff_drive"
  "0203216223fb8c1d3e2b8b595642daed")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Diff_drive>)))
  "Returns full string definition for message of type '<Diff_drive>"
  (cl:format cl:nil "float32 time_stamp~%float32 left_wheel_vel~%float32 right_wheel_vel~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Diff_drive)))
  "Returns full string definition for message of type 'Diff_drive"
  (cl:format cl:nil "float32 time_stamp~%float32 left_wheel_vel~%float32 right_wheel_vel~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Diff_drive>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Diff_drive>))
  "Converts a ROS message object to a list"
  (cl:list 'Diff_drive
    (cl:cons ':time_stamp (time_stamp msg))
    (cl:cons ':left_wheel_vel (left_wheel_vel msg))
    (cl:cons ':right_wheel_vel (right_wheel_vel msg))
))
