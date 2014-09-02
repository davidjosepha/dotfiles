set tabstop=4
set shiftwidth=4
set expandtab
set smarttab
set showcmd
set number
set ignorecase
set smartcase
set autoindent
set background=dark
set mouse=a
set noesckeys
set nocompatible
let mapleader = ","

filetype plugin indent on
syntax on

" Set up a way to toggle between relative and absolute line numbering
function! NumberToggle()
    if (&relativenumber)
        set norelativenumber 
    else
        set relativenumber
    endif
endfunc

nnoremap <leader>n :call NumberToggle()<cr>
