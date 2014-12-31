#include "arm_math.h"
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

/* ----------------------------------------------------------------------
** Test input signal contains 1000Hz + 15000 Hz
** ------------------------------------------------------------------- */

float32_t testInput_f32_1kHz_15kHz[320] =
{
+0.0000000000f, +0.5924659585f, -0.0947343455f, +0.1913417162f, +1.0000000000f, +0.4174197128f, +0.3535533906f, +1.2552931065f, 
+0.8660254038f, +0.4619397663f, +1.3194792169f, +1.1827865776f, +0.5000000000f, +1.1827865776f, +1.3194792169f, +0.4619397663f, 
+0.8660254038f, +1.2552931065f, +0.3535533906f, +0.4174197128f, +1.0000000000f, +0.1913417162f, -0.0947343455f, +0.5924659585f, 
-0.0000000000f, -0.5924659585f, +0.0947343455f, -0.1913417162f, -1.0000000000f, -0.4174197128f, -0.3535533906f, -1.2552931065f, 
-0.8660254038f, -0.4619397663f, -1.3194792169f, -1.1827865776f, -0.5000000000f, -1.1827865776f, -1.3194792169f, -0.4619397663f, 
-0.8660254038f, -1.2552931065f, -0.3535533906f, -0.4174197128f, -1.0000000000f, -0.1913417162f, +0.0947343455f, -0.5924659585f, 
+0.0000000000f, +0.5924659585f, -0.0947343455f, +0.1913417162f, +1.0000000000f, +0.4174197128f, +0.3535533906f, +1.2552931065f, 
+0.8660254038f, +0.4619397663f, +1.3194792169f, +1.1827865776f, +0.5000000000f, +1.1827865776f, +1.3194792169f, +0.4619397663f, 
+0.8660254038f, +1.2552931065f, +0.3535533906f, +0.4174197128f, +1.0000000000f, +0.1913417162f, -0.0947343455f, +0.5924659585f, 
+0.0000000000f, -0.5924659585f, +0.0947343455f, -0.1913417162f, -1.0000000000f, -0.4174197128f, -0.3535533906f, -1.2552931065f, 
-0.8660254038f, -0.4619397663f, -1.3194792169f, -1.1827865776f, -0.5000000000f, -1.1827865776f, -1.3194792169f, -0.4619397663f, 
-0.8660254038f, -1.2552931065f, -0.3535533906f, -0.4174197128f, -1.0000000000f, -0.1913417162f, +0.0947343455f, -0.5924659585f, 
+0.0000000000f, +0.5924659585f, -0.0947343455f, +0.1913417162f, +1.0000000000f, +0.4174197128f, +0.3535533906f, +1.2552931065f, 
+0.8660254038f, +0.4619397663f, +1.3194792169f, +1.1827865776f, +0.5000000000f, +1.1827865776f, +1.3194792169f, +0.4619397663f, 
+0.8660254038f, +1.2552931065f, +0.3535533906f, +0.4174197128f, +1.0000000000f, +0.1913417162f, -0.0947343455f, +0.5924659585f, 
+0.0000000000f, -0.5924659585f, +0.0947343455f, -0.1913417162f, -1.0000000000f, -0.4174197128f, -0.3535533906f, -1.2552931065f, 
-0.8660254038f, -0.4619397663f, -1.3194792169f, -1.1827865776f, -0.5000000000f, -1.1827865776f, -1.3194792169f, -0.4619397663f, 
-0.8660254038f, -1.2552931065f, -0.3535533906f, -0.4174197128f, -1.0000000000f, -0.1913417162f, +0.0947343455f, -0.5924659585f, 
-0.0000000000f, +0.5924659585f, -0.0947343455f, +0.1913417162f, +1.0000000000f, +0.4174197128f, +0.3535533906f, +1.2552931065f, 
+0.8660254038f, +0.4619397663f, +1.3194792169f, +1.1827865776f, +0.5000000000f, +1.1827865776f, +1.3194792169f, +0.4619397663f, 
+0.8660254038f, +1.2552931065f, +0.3535533906f, +0.4174197128f, +1.0000000000f, +0.1913417162f, -0.0947343455f, +0.5924659585f, 
-0.0000000000f, -0.5924659585f, +0.0947343455f, -0.1913417162f, -1.0000000000f, -0.4174197128f, -0.3535533906f, -1.2552931065f, 
-0.8660254038f, -0.4619397663f, -1.3194792169f, -1.1827865776f, -0.5000000000f, -1.1827865776f, -1.3194792169f, -0.4619397663f, 
-0.8660254038f, -1.2552931065f, -0.3535533906f, -0.4174197128f, -1.0000000000f, -0.1913417162f, +0.0947343455f, -0.5924659585f, 
+0.0000000000f, +0.5924659585f, -0.0947343455f, +0.1913417162f, +1.0000000000f, +0.4174197128f, +0.3535533906f, +1.2552931065f, 
+0.8660254038f, +0.4619397663f, +1.3194792169f, +1.1827865776f, +0.5000000000f, +1.1827865776f, +1.3194792169f, +0.4619397663f, 
+0.8660254038f, +1.2552931065f, +0.3535533906f, +0.4174197128f, +1.0000000000f, +0.1913417162f, -0.0947343455f, +0.5924659585f, 
+0.0000000000f, -0.5924659585f, +0.0947343455f, -0.1913417162f, -1.0000000000f, -0.4174197128f, -0.3535533906f, -1.2552931065f, 
-0.8660254038f, -0.4619397663f, -1.3194792169f, -1.1827865776f, -0.5000000000f, -1.1827865776f, -1.3194792169f, -0.4619397663f, 
-0.8660254038f, -1.2552931065f, -0.3535533906f, -0.4174197128f, -1.0000000000f, -0.1913417162f, +0.0947343455f, -0.5924659585f, 
-0.0000000000f, +0.5924659585f, -0.0947343455f, +0.1913417162f, +1.0000000000f, +0.4174197128f, +0.3535533906f, +1.2552931065f, 
+0.8660254038f, +0.4619397663f, +1.3194792169f, +1.1827865776f, +0.5000000000f, +1.1827865776f, +1.3194792169f, +0.4619397663f, 
+0.8660254038f, +1.2552931065f, +0.3535533906f, +0.4174197128f, +1.0000000000f, +0.1913417162f, -0.0947343455f, +0.5924659585f, 
+0.0000000000f, -0.5924659585f, +0.0947343455f, -0.1913417162f, -1.0000000000f, -0.4174197128f, -0.3535533906f, -1.2552931065f, 
-0.8660254038f, -0.4619397663f, -1.3194792169f, -1.1827865776f, -0.5000000000f, -1.1827865776f, -1.3194792169f, -0.4619397663f, 
-0.8660254038f, -1.2552931065f, -0.3535533906f, -0.4174197128f, -1.0000000000f, -0.1913417162f, +0.0947343455f, -0.5924659585f, 
-0.0000000000f, +0.5924659585f, -0.0947343455f, +0.1913417162f, +1.0000000000f, +0.4174197128f, +0.3535533906f, +1.2552931065f, 
+0.8660254038f, +0.4619397663f, +1.3194792169f, +1.1827865776f, +0.5000000000f, +1.1827865776f, +1.3194792169f, +0.4619397663f, 
+0.8660254038f, +1.2552931065f, +0.3535533906f, +0.4174197128f, +1.0000000000f, +0.1913417162f, -0.0947343455f, +0.5924659585f, 
+0.0000000000f, -0.5924659585f, +0.0947343455f, -0.1913417162f, -1.0000000000f, -0.4174197128f, -0.3535533906f, -1.2552931065f, 
};

float32_t refOutput[320] = 
{
+0.0000000000f, -0.0010797829f, -0.0007681386f, -0.0001982932f, +0.0000644313f, +0.0020854271f, +0.0036891871f, +0.0015855941f, 
-0.0026280805f, -0.0075907658f, -0.0119390538f, -0.0086665968f, +0.0088981202f, +0.0430539279f, +0.0974468742f, +0.1740405600f, 
+0.2681416601f, +0.3747720089f, +0.4893362230f, +0.6024154672f, +0.7058740791f, +0.7968348987f, +0.8715901940f, +0.9277881093f, 
+0.9682182661f, +0.9934674267f, +1.0012052245f, +0.9925859371f, +0.9681538347f, +0.9257026822f, +0.8679010068f, +0.7952493046f, 
+0.7085021596f, +0.6100062330f, +0.5012752767f, +0.3834386057f, +0.2592435399f, +0.1309866321f, -0.0000000000f, -0.1309866321f, 
-0.2592435399f, -0.3834386057f, -0.5012752767f, -0.6100062330f, -0.7085021596f, -0.7952493046f, -0.8679010068f, -0.9257026822f, 
-0.9681538347f, -0.9936657199f, -1.0019733630f, -0.9936657199f, -0.9681538347f, -0.9257026822f, -0.8679010068f, -0.7952493046f, 
-0.7085021596f, -0.6100062330f, -0.5012752767f, -0.3834386057f, -0.2592435399f, -0.1309866321f, +0.0000000000f, +0.1309866321f, 
+0.2592435399f, +0.3834386057f, +0.5012752767f, +0.6100062330f, +0.7085021596f, +0.7952493046f, +0.8679010068f, +0.9257026822f, 
+0.9681538347f, +0.9936657199f, +1.0019733630f, +0.9936657199f, +0.9681538347f, +0.9257026822f, +0.8679010068f, +0.7952493046f, 
+0.7085021596f, +0.6100062330f, +0.5012752767f, +0.3834386057f, +0.2592435399f, +0.1309866321f, -0.0000000000f, -0.1309866321f, 
-0.2592435399f, -0.3834386057f, -0.5012752767f, -0.6100062330f, -0.7085021596f, -0.7952493046f, -0.8679010068f, -0.9257026822f, 
-0.9681538347f, -0.9936657199f, -1.0019733630f, -0.9936657199f, -0.9681538347f, -0.9257026822f, -0.8679010068f, -0.7952493046f, 
-0.7085021596f, -0.6100062330f, -0.5012752767f, -0.3834386057f, -0.2592435399f, -0.1309866321f, +0.0000000000f, +0.1309866321f, 
+0.2592435399f, +0.3834386057f, +0.5012752767f, +0.6100062330f, +0.7085021596f, +0.7952493046f, +0.8679010068f, +0.9257026822f, 
+0.9681538347f, +0.9936657199f, +1.0019733630f, +0.9936657199f, +0.9681538347f, +0.9257026822f, +0.8679010068f, +0.7952493046f, 
+0.7085021596f, +0.6100062330f, +0.5012752767f, +0.3834386057f, +0.2592435399f, +0.1309866321f, -0.0000000000f, -0.1309866321f, 
-0.2592435399f, -0.3834386057f, -0.5012752767f, -0.6100062330f, -0.7085021596f, -0.7952493046f, -0.8679010068f, -0.9257026822f, 
-0.9681538347f, -0.9936657199f, -1.0019733630f, -0.9936657199f, -0.9681538347f, -0.9257026822f, -0.8679010068f, -0.7952493046f, 
-0.7085021596f, -0.6100062330f, -0.5012752767f, -0.3834386057f, -0.2592435399f, -0.1309866321f, +0.0000000000f, +0.1309866321f, 
+0.2592435399f, +0.3834386057f, +0.5012752767f, +0.6100062330f, +0.7085021596f, +0.7952493046f, +0.8679010068f, +0.9257026822f, 
+0.9681538347f, +0.9936657199f, +1.0019733630f, +0.9936657199f, +0.9681538347f, +0.9257026822f, +0.8679010068f, +0.7952493046f, 
+0.7085021596f, +0.6100062330f, +0.5012752767f, +0.3834386057f, +0.2592435399f, +0.1309866321f, +0.0000000000f, -0.1309866321f, 
-0.2592435399f, -0.3834386057f, -0.5012752767f, -0.6100062330f, -0.7085021596f, -0.7952493046f, -0.8679010068f, -0.9257026822f, 
-0.9681538347f, -0.9936657199f, -1.0019733630f, -0.9936657199f, -0.9681538347f, -0.9257026822f, -0.8679010068f, -0.7952493046f, 
-0.7085021596f, -0.6100062330f, -0.5012752767f, -0.3834386057f, -0.2592435399f, -0.1309866321f, +0.0000000000f, +0.1309866321f, 
+0.2592435399f, +0.3834386057f, +0.5012752767f, +0.6100062330f, +0.7085021596f, +0.7952493046f, +0.8679010068f, +0.9257026822f, 
+0.9681538347f, +0.9936657199f, +1.0019733630f, +0.9936657199f, +0.9681538347f, +0.9257026822f, +0.8679010068f, +0.7952493046f, 
+0.7085021596f, +0.6100062330f, +0.5012752767f, +0.3834386057f, +0.2592435399f, +0.1309866321f, +0.0000000000f, -0.1309866321f, 
-0.2592435399f, -0.3834386057f, -0.5012752767f, -0.6100062330f, -0.7085021596f, -0.7952493046f, -0.8679010068f, -0.9257026822f, 
-0.9681538347f, -0.9936657199f, -1.0019733630f, -0.9936657199f, -0.9681538347f, -0.9257026822f, -0.8679010068f, -0.7952493046f, 
-0.7085021596f, -0.6100062330f, -0.5012752767f, -0.3834386057f, -0.2592435399f, -0.1309866321f, -0.0000000000f, +0.1309866321f, 
+0.2592435399f, +0.3834386057f, +0.5012752767f, +0.6100062330f, +0.7085021596f, +0.7952493046f, +0.8679010068f, +0.9257026822f, 
+0.9681538347f, +0.9936657199f, +1.0019733630f, +0.9936657199f, +0.9681538347f, +0.9257026822f, +0.8679010068f, +0.7952493046f, 
+0.7085021596f, +0.6100062330f, +0.5012752767f, +0.3834386057f, +0.2592435399f, +0.1309866321f, +0.0000000000f, -0.1309866321f, 
-0.2592435399f, -0.3834386057f, -0.5012752767f, -0.6100062330f, -0.7085021596f, -0.7952493046f, -0.8679010068f, -0.9257026822f, 
-0.9681538347f, -0.9936657199f, -1.0019733630f, -0.9936657199f, -0.9681538347f, -0.9257026822f, -0.8679010068f, -0.7952493046f, 
-0.7085021596f, -0.6100062330f, -0.5012752767f, -0.3834386057f, -0.2592435399f, -0.1309866321f, +0.0000000000f, +0.1309866321f, 
+0.2592435399f, +0.3834386057f, +0.5012752767f, +0.6100062330f, +0.7085021596f, +0.7952493046f, +0.8679010068f, +0.9257026822f, 
+0.9681538347f, +0.9936657199f, +1.0019733630f, +0.9936657199f, +0.9681538347f, +0.9257026822f, +0.8679010068f, +0.7952493046f 
};

