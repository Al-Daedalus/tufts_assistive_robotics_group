;; Auto-generated. Do not edit!


(when (boundp 'encoder_msgs::Encoder)
  (if (not (find-package "ENCODER_MSGS"))
    (make-package "ENCODER_MSGS"))
  (shadow 'Encoder (find-package "ENCODER_MSGS")))
(unless (find-package "ENCODER_MSGS::ENCODER")
  (make-package "ENCODER_MSGS::ENCODER"))

(in-package "ROS")
;;//! \htmlinclude Encoder.msg.html


(defclass encoder_msgs::Encoder
  :super ros::object
  :slots (_time_stamp _left_encoder_count _right_encoder_count ))

(defmethod encoder_msgs::Encoder
  (:init
   (&key
    ((:time_stamp __time_stamp) 0.0)
    ((:left_encoder_count __left_encoder_count) 0)
    ((:right_encoder_count __right_encoder_count) 0)
    )
   (send-super :init)
   (setq _time_stamp (float __time_stamp))
   (setq _left_encoder_count (round __left_encoder_count))
   (setq _right_encoder_count (round __right_encoder_count))
   self)
  (:time_stamp
   (&optional __time_stamp)
   (if __time_stamp (setq _time_stamp __time_stamp)) _time_stamp)
  (:left_encoder_count
   (&optional __left_encoder_count)
   (if __left_encoder_count (setq _left_encoder_count __left_encoder_count)) _left_encoder_count)
  (:right_encoder_count
   (&optional __right_encoder_count)
   (if __right_encoder_count (setq _right_encoder_count __right_encoder_count)) _right_encoder_count)
  (:serialization-length
   ()
   (+
    ;; float32 _time_stamp
    4
    ;; int64 _left_encoder_count
    8
    ;; int64 _right_encoder_count
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _time_stamp
       (sys::poke _time_stamp (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int64 _left_encoder_count
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _left_encoder_count (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _left_encoder_count) (= (length (_left_encoder_count . bv)) 2)) ;; bignum
              (write-long (ash (elt (_left_encoder_count . bv) 0) 0) s)
              (write-long (ash (elt (_left_encoder_count . bv) 1) -1) s))
             ((and (class _left_encoder_count) (= (length (_left_encoder_count . bv)) 1)) ;; big1
              (write-long (elt (_left_encoder_count . bv) 0) s)
              (write-long (if (>= _left_encoder_count 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _left_encoder_count s)(write-long (if (>= _left_encoder_count 0) 0 #xffffffff) s)))
     ;; int64 _right_encoder_count
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _right_encoder_count (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _right_encoder_count) (= (length (_right_encoder_count . bv)) 2)) ;; bignum
              (write-long (ash (elt (_right_encoder_count . bv) 0) 0) s)
              (write-long (ash (elt (_right_encoder_count . bv) 1) -1) s))
             ((and (class _right_encoder_count) (= (length (_right_encoder_count . bv)) 1)) ;; big1
              (write-long (elt (_right_encoder_count . bv) 0) s)
              (write-long (if (>= _right_encoder_count 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _right_encoder_count s)(write-long (if (>= _right_encoder_count 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _time_stamp
     (setq _time_stamp (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int64 _left_encoder_count
#+(or :alpha :irix6 :x86_64)
      (setf _left_encoder_count (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _left_encoder_count (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _right_encoder_count
#+(or :alpha :irix6 :x86_64)
      (setf _right_encoder_count (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _right_encoder_count (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get encoder_msgs::Encoder :md5sum-) "b66af2928dcdc45aac405392cc8c0f5c")
(setf (get encoder_msgs::Encoder :datatype-) "encoder_msgs/Encoder")
(setf (get encoder_msgs::Encoder :definition-)
      "float32 time_stamp
int64 left_encoder_count
int64 right_encoder_count

")



(provide :encoder_msgs/Encoder "b66af2928dcdc45aac405392cc8c0f5c")


