#!/bin/sh
# for creatings tags
# goto the root , assuming i work under t1
cd ..
ctags -R -I --languages=c++ --c++-kinds=+p --fields=+iaS --extra=+q ~/t

