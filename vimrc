" General settings
set mouse=a
set nocompatible              " Use Vim settings, rather than Vi settings
filetype plugin indent on     " Enable filetype detection, plugins, and indentation
syntax on                     " Enable syntax highlighting
set undofile					" Remember undo history
set undodir=~/.vim/undodir
set foldmethod=syntax			" Enable folding based on indent
set foldlevelstart=10
set foldnestmax=3
au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g`\"" | endif		" Enable persistent cursor postition
set wildmenu					" Display command line's tab complete options as a menu
set noswapfile					" Disable swap file
set nobackup
set nowritebackup
set autowrite					" Automatically write files before opening another file
set autoread					" Reload all files if changed externally

" UI settings
set number
set relativenumber            " Show line numbers
set showcmd                   " Show (partial) command in the status line
set cursorline                " Highlight the current line
set cursorcolumn				" Highlight the current column
highlight CursorColumn guibg=grey20 ctermbg=235
set ruler						" Always show cursor position
set wildmenu                  " Show a command-line completion menu
set showmatch                 " Show matching brackets/parentheses
set incsearch                 " Show search matches as you type
set hlsearch                  " Highlight all search matches

" Indentation settings
set noexpandtab                 " Use spaces instead of tabs
set tabstop=4                 " Number of spaces a tab counts for
set shiftwidth=4              " Number of spaces for each auto-indent step
set smartindent               " Enable smart auto-indentation
set autoindent                " Enable auto-indentation
set smarttab                  " Use shiftwidth for tab commands

" Key mappings (general)
inoremap ww <Esc>:w<CR>
vnoremap ww <Esc>:w<CR>
nnoremap ww :w<CR>
inoremap ij <Esc>1
vnoremap ij <Esc>1
nnoremap ij <Esc>1
nnoremap <leader><leader> :wq<CR>
inoremap <leader><leader> <Esc>:wq<CR>
vnoremap <leader><leader> <Esc>:wq<CR>
nnoremap zm zM

" Key mappings (NERDTree) 
nnoremap nn :NERDTreeToggle<CR>
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l
nnoremap <silent> > :tabn<CR>
nnoremap <silent> < :tabp<CR>

"Key mappings (auto-pairs)
vnoremap { <Esc>`>a}<Esc>`<i{<Esc>
vnoremap ( <Esc>`>a)<Esc>`<i(<Esc>
vnoremap [ <Esc>`>a]<Esc>`<i[<Esc>
vnoremap ' <Esc>`>a'<Esc>`<i'<Esc>
vnoremap " <Esc>`>a"<Esc>`<i"<Esc>

" C-specific settings
autocmd FileType c setlocal cindent " Enable C indentation

" Plugins (optional)
" You can install plugins to extend Vim's functionality. Here's an example using Vundle:
" Install Vundle: https://github.com/VundleVim/Vundle.vim
" Add the following lines to your .vimrc:

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" let Vundle manage Vundle, required
" Issue the following commands on a new pc:
" git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
" vim +PluginInstall +qall
Plugin 'VundleVim/Vundle.vim'

" Add your plugins here
Plugin 'preservim/nerdtree'
Plugin 'dense-analysis/ale'
Plugin 'jiangmiao/auto-pairs'
Plugin 'tpope/vim-commentary'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required

" Customize the appearance of your installed plugins
" For example, to customize lightline.vim:
" let g:lightline = { 'colorscheme': 'wombat' }
