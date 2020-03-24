scriptencoding utf-8

set nocompatible
set modeline " default
set writebackup
set noswapfile
set showtabline=2 " memo: always
set hidden
set encoding=utf-8
set ambiwidth=double
set nostartofline
set clipboard+=unnamed
set backspace= " default
set history=1000
set virtualedit= " memo: block
set cursorline
set showcmd " default
set notitle " default
set norelativenumber " default
set ruler
set wrap " default
set conceallevel=0 " default
set list listchars=tab:>.,trail:_,eol:?
set wildchar=<Tab> " default
set wildmenu
set wildmode=longest:full,full
set cmdheight=2
set laststatus=2
set showmatch
set matchtime=5 " default
set nowrapscan
set incsearch
set hlsearch
set autoindent
set smartindent
set smarttab
set shiftwidth=2 " memo: cindent, >>, <<, etc
set tabstop=2
set softtabstop=2
set expandtab
set completeopt=menu,preview " default
set complete+=k
set dictionary=
" CTRL-X CTRL-O
set omnifunc= " default
" CTRL-X CTRL-U
set completefunc= " default
function! CleverTab()
  if strpart( getline('.'), 0, col('.')-1 ) =~ '^\s*$'
    return "\<Tab>"
  else
    return "\<C-N>"
  endif
endfunction
inoremap <Tab> <C-R>=CleverTab()<CR>
inoremap <C-A> <Home>
inoremap <C-E> <End>
inoremap <C-F> <Right>
inoremap <C-B> <Left>
inoremap <Esc>b <S-Left>
inoremap <Esc>f <S-Right>

set cedit=\<Esc>
cnoremap <C-A> <Home>
cnoremap <C-F> <Right>
cnoremap <C-B> <Left>
cnoremap <Esc>b <S-Left>
cnoremap <Esc>f <S-Right>

nnoremap - :edit %:h<CR>

call plug#begin('~/.vim/plugged')
Plug 'junegunn/vim-plug'
Plug 'kana/vim-textobj-user'
Plug 'kana/vim-smartinput'
Plug 'tpope/vim-surround'
Plug 'tpope/vim-repeat'
Plug 'tpope/vim-unimpaired'
Plug 'tomtom/tcomment_vim'
Plug 'scrooloose/nerdtree'
call plug#end()

augroup vimrc
  autocmd!
augroup END

autocmd vimrc FileType c,h,cpp setlocal shiftwidth=4 tabstop=4 softtabstop=4 dictionary=cpp.dict
