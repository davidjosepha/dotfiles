" begin vundle
set nocompatible
filetype off

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'VundleVim/Vundle.vim'

Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
set laststatus=2
let g:airline_theme='solarized'

"Plugin 'wincent/command-t'
Plugin 'kien/ctrlp.vim'
let g:ctrlp_map = '<c-p>'
let g:ctrlp_cmd = 'CtrlP'

Plugin 'rking/ag.vim'
Plugin 'tpope/vim-fugitive' " git
Plugin 'fatih/vim-go' " go

call vundle#end()
filetype plugin indent on
" end vundle

set tabstop=4
set shiftwidth=4
set expandtab
set smarttab
set showcmd
set number
set ignorecase
set smartcase
set autoindent
"set background=dark
set mouse=a
" caused problem with arrow keys in insert mode, solved with "nocompatible"
set noesckeys
set nocompatible
let mapleader = ","

" filetype specific
autocmd FileType c setlocal expandtab shiftwidth=4 softtabstop=4
autocmd FileType go setlocal noexpandtab shiftwidth=4 tabstop=4 softtabstop=4
autocmd FileType scheme setlocal expandtab shiftwidth=2 softtabstop=2

autocmd FileType cpp setlocal expandtab shiftwidth=4 softtabstop=4
autocmd FileType python setlocal expandtab shiftwidth=4 softtabstop=4
autocmd FileType php setlocal expandtab shiftwidth=4 softtabstop=4

autocmd FileType html setlocal expandtab
autocmd FileType css setlocal expandtab
autocmd FileType javascript setlocal expandtab

autocmd FileType yaml setlocal expandtab

" mark 80 lines
set colorcolumn=81
highlight ColorColumn ctermbg=9 ctermfg=7

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

"colors peachpuff

set clipboard^=unnamed
