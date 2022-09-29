add_library(libparta parta.c parta.h)
target_include_directories(libparta PUBLIC .)
target_compile_options(libparta PRIVATE -Wall -Wextra -Wvla -ggdb -fsanitize=address)
target_compile_features(libparta PUBLIC c_std_11)

add_library(libpartb partb.c partb.h)
target_include_directories(libpartb PUBLIC .)
target_compile_options(libpartb PRIVATE -Wall -Wextra -Wvla -ggdb -fsanitize=address)
target_compile_features(libpartb PUBLIC c_std_11)

add_library(libpartc partc.c partc.h)
target_include_directories(libpartc PUBLIC .)
target_compile_options(libpartc PRIVATE -Wall -Wextra -Wvla -ggdb -fsanitize=address)
target_compile_features(libpartc PUBLIC c_std_11)
