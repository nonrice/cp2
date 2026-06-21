let g:repo_path = expand('<sfile>:p:h')
let $RT = g:repo_path

nnoremap <leader>pl :r $RT/library/
nnoremap <leader>pt :e /tmp/in.txt<CR>
nnoremap <leader>pr :!make run -C $RT FILE=%:p<CR>
