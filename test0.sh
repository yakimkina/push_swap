#A STACK WITH 100 RANDOM NUMBERS

ARG100="17 9 93 80 99 2 5 51 84 4 57 48 14 29 55 35 74 21 94 60 68 63 1 92 23 82 12 67 69 98 52 19 83 97 78 39 75 100 25 24 8 7 41 11 86 44 36 72 18 73 16 64 47 90 65 87 77 59 61 45 30 53 54 66 76 28 37 95 70 91 27 6 50 43 81 3 46 13 31 89 88 96 38 62 33 10 15 79 20 42 40 85 26 34 71 49 32 22 58 56";
ARG500="458 276 412 12 557 29 552 296 134 84 380 23 147 68 355 88 106 189 266 123 503 450 120 6 255 167 391 444 153 260 369 95 410 155 400 537 195 393 569 381 122 157 500 595 108 473 334 316 148 583 351 359 281 299 370 533 203 131 442 270 293 181 415 530 236 291 56 558 478 550 170 304 529 173 288 357 237 142 329 396 128 554 515 113 259 185 539 254 531 69 438 534 556 234 150 421 105 344 446 262 26 133 198 70 274 225 32 302 453 243 208 321 427 492 365 127 211 496 229 115 383 482 517 28 339 541 48 483 591 525 194 406 547 394 199 523 18 187 37 89 53 426 382 502 508 145 354 202 217 190 486 63 467 295 449 549 330 136 248 221 564 241 435 33 87 372 368 272 117 285 546 21 326 440 385 411 333 238 102 489 40 512 64 459 553 342 576 516 27 599 505 73 454 327 524 175 78 585 54 574 15 9 307 146 116 573 464 477 233 121 572 405 219 461 79 91 361 447 332 341 455 22 298 472 144 335 323 441 76 308 218 311 42 485 490 319 443 222 232 598 425 16 5 494 269 460 317 466 358 240 571 399 520 314 402 44 310 159 10 172 39 499 83 11 428 300 375 379 171 544 278 363 92 364 101 143 371 282 392 578 434 360 239 536 501 487 388 401 551 519 178 498 35 192 484 124 62 575 36 58 417 559 20 347 322 287 245 430 174 384 74 408 30 509 324 210 250 182 154 99 207 103 24 2 567 7 592 97 43 212 352 251 109 168 568 162 98 90 179 374 563 161 521 235 386 156 543 85 422 306 183 51 286 57 429 600 318 395 356 457 586 376 456 437 581 474 114 25 343 377 17 424 294 320 346 463 275 565 47 197 81 126 71 538 555 8 582 257 479 65 246 297 205 350 201 158 407 82 289 280 419 373 1 273 545 209 61 45 528 118 38 137 152 186 413 244 191 584 597 593 309 423 353 513 14 164 196 338 177 111 223 3 77 268 215 409 204 540 112 301 140 265 180 416 94 263 504 526 67 312 495 398 366 252 367 60 52 277 34 522 110 267 436 431 506 527 41 227 345 349 242 588 231 439 390 414 397 475 206 510 151 66 560 228 587 256 480 292 193 328 138 247 135 141 445 570 50 216 488 130";

#A STACK WITH  10 RANDOM NUMBERS.

ARG10="33 4 5 9 6 2 1 99 40 92"

#RETURNS COUNT OF OPERATIONS IT TOOK TO SORT DEPENDING ON THE ARG.

#./push_swap $ARG100 | wc -l

#TAKES OPERATIONS PRODUCED BY PUSH_SWAP TO CHECKER AND DISPLAYS OK IF SORTED & KO IF NOT.

./push_swap $ARG500 | ./my_checker $ARG500

#"I WROTE A STUPID ALGO IT WORKS BUT NOT EFFICIENT" - Tshilidzi Tshivhula

#DON'T BE STUPID USE THE CORRECT STACK WHEN TESTING TO AVOID UNEXPECTED BEHAVIOUR