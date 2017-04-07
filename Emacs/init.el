(setq gc-cons-threshold (* 20 1024 1024)) 

(require 'package)
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/"))
(package-initialize)

(unless (package-installed-p 'use-package)
  (package-refresh-contents)
  (package-install 'use-package))

(load-theme 'misterioso)
(tool-bar-mode -1)
(display-splash-screen -1)
(save-place-mode 1)
(global-linum-mode 1)

(prefer-coding-system 'utf-8)
(set-buffer-file-coding-system 'utf-8)
(fset 'yes-or-no-p 'y-or-n-p)
(global-set-key (kbd "C-x k") #'kill-this-buffer)


;; I like my backups hidden and in abundance
(unless (file-exists-p "~/.emacs.d/backups")
  (mkdir "~/.emacs.d/backups/per-save" t)
  (mkdir "~/.emacs.d/backups/per-session" t))

 (setq backup-directory-alist '(("" . "~/.emacs.d/backups/per-save"))
       backup-by-copying t
       delete-old-versions t
       kept-new-versions 10
       kept-old-versions 0
       auto-save-default nil
       vc-make-backup-files t
       version-control t)

(defun force-backup-of-buffer ()
  "Always save file backups on save."
  (unless buffer-backed-up
    (let ((backup-directory-alist '(("" . "~/.emacs.d/backups/per-session"))))
      (backup-buffer)))
  (let ((buffer-backed-up nil))
    (backup-buffer)))
(add-hook 'before-save-hook  'force-backup-of-buffer)

(use-package projectile
  :ensure t
  :config
  (projectile-global-mode))

(use-package ivy
  :ensure t
  :ensure smex
  :config
  (setq projectile-completion-system 'ivy
	ivy-height 15
	ivy-count-format "(%d/%d) "
	ivy-display-style 'fancy) 
  (ivy-mode 1))

(use-package company
  :ensure t
  :config
  (add-hook 'prog-mode-hook 'company-mode)
  (setq company-idle-delay 0
	company-minimum-prefix-length 2
	company-tooltip-align-annotations t
	company-require-match nil))


(use-package company-jedi
  :ensure t
  :bind (:map python-mode-map
	      ("M-." . jedi:goto-definition)
	      ("M-," . jedi:goto-definition-pop-marker))
  :init
  (add-hook 'python-mode-hook (lambda () (add-to-list 'company-backends 'company-jedi))))

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(inhibit-startup-screen t)
 '(package-selected-packages (quote (projectile company ivy use-package))))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
