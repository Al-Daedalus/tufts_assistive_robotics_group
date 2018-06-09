;; Auto-generated. Do not edit!


(when (boundp 'bill_diff_drive::Diff_drive)
  (if (not (find-package "BILL_DIFF_DRIVE"))
    (make-package "BILL_DIFF_DRIVE"))
  (shadow 'Diff_drive (find-package "BILL_DIFF_DRIVE")))
(unless (find-package "BILL_DIFF_DRIVE::DIFF_DRIVE")
  (make-package "BILL_DIFF_DRIVE::DIFF_DRIVE"))

(in-package "ROS")
;;//! \htmlinclude Diff_drive.msg.html


(defclass bill_diff_drive::Diff_drive
  :super ros::object
  :slots (_time_stamp _left_wheel_vel _right_wheel_vel ))

(defmethod bill_diff_drive::Diff_drive
  (:init
   (&key
    ((:time_stamp __time_stamp) 0.0)
    ((:left_wheel_vel __left_wheel_vel) 0.0)
    ((:right_wheel_vel __right_wheel_vel) 0.0)
    )
   (send-super :init)
   (setq _time_stamp (float __time_stamp))
   (setq _left_wheel_vel (float __left_wheel_vel))
   (setq _right_wheel_vel (float __right_wheel_vel))
   self)
  (:time_stamp
   (&optional __time_stamp)
   (if __time_stamp (setq _time_stamp __time_stamp)) _time_stamp)
  (:left_wheel_vel
   (&optional __left_wheel_vel)
   (if __left_wheel_vel (setq _left_wheel_vel __left_wheel_vel)) _left_wheel_vel)
  (:right_wheel_vel
   (&optional __right_wheel_vel)
   (if __right_wheel_vel (setq _right_wheel_vel __right_wheel_vel)) _right_wheel_vel)
  (:serialization-length
   ()
   (+
    ;; float32 _time_stamp
    4
    ;; float32 _left_wheel_vel
    4
    ;; float32 _right_wheel_vel
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _time_stamp
       (sys::poke _time_stamp (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _left_wheel_vel
       (sys::poke _left_wheel_vel (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _right_wheel_vel
       (sys::poke _right_wheel_vel (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _time_stamp
     (setq _time_stamp (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _left_wheel_vel
     (setq _left_wheel_vel (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _right_wheel_vel
     (setq _right_wheel_vel (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get bill_diff_drive::Diff_drive :md5sum-) "0203216223fb8c1d3e2b8b595642daed")
(setf (get bill_diff_drive::Diff_drive :datatype-) "bill_diff_drive/Diff_drive")
(setf (get bill_diff_drive::Diff_drive :definition-)
      "float32 time_stamp
float32 left_wheel_vel
float32 right_wheel_vel

")



(provide :bill_diff_drive/Diff_drive "0203216223fb8c1d3e2b8b595642daed")


