g++ -std=c++17 \
    -m64 -march=sandybridge -mavx -mno-vzeroupper \
    -O3 \
    -fno-stack-protector -fpermissive -fno-ipa-cp-clone -fno-ipa-cp -fno-unroll-loops -fno-unswitch-loops \
    -Wno-pmf-conversions -Wall -Wextra -Werror=return-type \
    -pthread \
    test2.cc

