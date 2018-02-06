(
        (IF_EQ h 0
            (
                (LOAD_PIXEL h 255 199)
            )
        )
        (IF_EQ h 255
            (
                (LOAD_PIXEL h 255 200)
            )
        )
        (IF_EQ v 200
            (
                (SUB_VEC3 1 0 0)
            )
        )
        (IF_EQ v 199
            (
                (ADD_VEC3 1 0 0)
            )
        )
        (SHOW_HSV)
)
