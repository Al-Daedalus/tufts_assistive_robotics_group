
(cl:in-package :asdf)

(defsystem "bill_diff_drive-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Diff_drive" :depends-on ("_package_Diff_drive"))
    (:file "_package_Diff_drive" :depends-on ("_package"))
  ))