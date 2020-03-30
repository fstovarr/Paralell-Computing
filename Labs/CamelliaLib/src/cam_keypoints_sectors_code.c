const int CamKeypointSectors[CAM_NB_SECTORS][MAX_PIX_PER_SECTOR] = {
	{440, 441, 442, 443, 444, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, -1},
	{347, 377, 378, 379, 380, 406, 407, 408, 409, 410, 411, 412, 435, 436, 437, 438, 439, 464, 465, -1},
	{282, 313, 314, 315, 343, 344, 345, 346, 373, 374, 375, 376, 403, 404, 405, 434, -1},
	{217, 248, 249, 250, 279, 280, 281, 310, 311, 312, 340, 341, 342, 371, 372, 402, 433, -1},
	{183, 184, 214, 215, 216, 245, 246, 247, 276, 277, 278, 308, 309, 339, 370, 401, 432, 463, -1},
	{118, 149, 150, 151, 180, 181, 182, 212, 213, 243, 244, 275, 306, 307, 338, 369, 400, -1},
	{84, 115, 116, 117, 147, 148, 178, 179, 210, 211, 242, 273, 274, 305, 337, 368, -1},
	{49, 50, 81, 82, 83, 113, 114, 145, 146, 177, 208, 209, 240, 241, 272, 304, 336, 399, 431, -1},
	{47, 48, 79, 80, 111, 112, 143, 144, 175, 176, 207, 239, 271, 303, 335, 367, -1},
	{45, 46, 77, 78, 109, 110, 141, 142, 173, 174, 206, 238, 270, 302, 334, 366, -1},
	{43, 44, 74, 75, 76, 107, 108, 139, 140, 172, 204, 205, 236, 237, 269, 301, 333, 398, 430, -1},
	{73, 104, 105, 106, 137, 138, 170, 171, 202, 203, 235, 267, 268, 300, 332, 365, -1},
	{103, 134, 135, 136, 167, 168, 169, 200, 201, 233, 234, 266, 298, 299, 331, 364, 397, -1},
	{165, 166, 197, 198, 199, 230, 231, 232, 263, 264, 265, 296, 297, 330, 363, 396, 429, 462, -1},
	{196, 227, 228, 229, 260, 261, 262, 293, 294, 295, 327, 328, 329, 361, 362, 395, 428, -1},
	{259, 290, 291, 292, 323, 324, 325, 326, 357, 358, 359, 360, 392, 393, 394, 427, -1},
	{322, 353, 354, 355, 356, 385, 386, 387, 388, 389, 390, 391, 422, 423, 424, 425, 426, 460, 461, -1},
	{417, 418, 419, 420, 421, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, -1},
	{481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 513, 514, 515, 516, 517, -1},
	{492, 493, 518, 519, 520, 521, 522, 545, 546, 547, 548, 549, 550, 551, 577, 578, 579, 580, 610, -1},
	{523, 552, 553, 554, 581, 582, 583, 584, 611, 612, 613, 614, 642, 643, 644, 675, -1},
	{524, 555, 585, 586, 615, 616, 617, 645, 646, 647, 676, 677, 678, 707, 708, 709, 740, -1},
	{494, 525, 556, 587, 618, 648, 649, 679, 680, 681, 710, 711, 712, 741, 742, 743, 773, 774, -1},
	{557, 588, 619, 650, 651, 682, 713, 714, 744, 745, 775, 776, 777, 806, 807, 808, 839, -1},
	{589, 620, 652, 683, 684, 715, 746, 747, 778, 779, 809, 810, 840, 841, 842, 873, -1},
	{526, 558, 621, 653, 685, 716, 717, 748, 749, 780, 811, 812, 843, 844, 874, 875, 876, 907, 908, -1},
	{590, 622, 654, 686, 718, 750, 781, 782, 813, 814, 845, 846, 877, 878, 909, 910, -1},
	{591, 623, 655, 687, 719, 751, 783, 784, 815, 816, 847, 848, 879, 880, 911, 912, -1},
	{527, 559, 624, 656, 688, 720, 721, 752, 753, 785, 817, 818, 849, 850, 881, 882, 883, 913, 914, -1},
	{592, 625, 657, 689, 690, 722, 754, 755, 786, 787, 819, 820, 851, 852, 853, 884, -1},
	{560, 593, 626, 658, 659, 691, 723, 724, 756, 757, 788, 789, 790, 821, 822, 823, 854, -1},
	{495, 528, 561, 594, 627, 660, 661, 692, 693, 694, 725, 726, 727, 758, 759, 760, 791, 792, -1},
	{529, 562, 595, 596, 628, 629, 630, 662, 663, 664, 695, 696, 697, 728, 729, 730, 761, -1},
	{530, 563, 564, 565, 597, 598, 599, 600, 631, 632, 633, 634, 665, 666, 667, 698, -1},
	{496, 497, 531, 532, 533, 534, 535, 566, 567, 568, 569, 570, 571, 572, 601, 602, 603, 604, 635, -1},
	{498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 536, 537, 538, 539, 540, -1}
};
