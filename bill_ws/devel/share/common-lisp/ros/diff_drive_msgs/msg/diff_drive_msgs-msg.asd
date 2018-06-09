
(cl:in-package :asdf)

(defsystem "diff_drive_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Diff_drive" :depends-on ("_package_Diff_drive"))
    (:file "_package_Diff_drive" :depends-on ("_package"))
  ))