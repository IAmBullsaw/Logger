(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(custom-enabled-themes (quote (misterioso)))
 '(inhibit-startup-screen t))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

(font-lock-add-keywords 'text-mode
  '(("\\([\\[]INFO[A-Za-z0-9\s-:]+\\]\s\\)" 1 font-lock-comment-face prepend)
    ))

(font-lock-add-keywords 'text-mode
  '(("\\([\\[]WARN[A-Za-z0-9\s-:]+\\]\s\\)" 1 font-lock-function-name-face prepend)
    ))

(font-lock-add-keywords 'text-mode
  '(("\\([\\[][A-Za-z0-9\s-:]ERR[A-Za-z0-9\s-:]+\\]\s\\)" 1 font-lock-warning-face prepend)
    ))
