[1 of 1] Compiling Main             ( a.hs, a.o )

==================== Tidy Core ====================
Result size of Tidy Core = {terms: 74, types: 93, coercions: 0}

Main.main :: GHC.Types.IO ()
[GblId]
Main.main =
  GHC.Base.$
    @ GHC.Integer.Type.Integer
    @ (GHC.Types.IO ())
    (System.IO.print @ GHC.Integer.Type.Integer GHC.Show.$fShowInteger)
    (GHC.Base.$
       @ (forall s_as1. GHC.ST.ST s_as1 GHC.Integer.Type.Integer)
       @ GHC.Integer.Type.Integer
       (GHC.ST.runST @ GHC.Integer.Type.Integer)
       (\ (@ s_as9) ->
          let {
            $dMArray_aFR
              :: Data.Array.Base.MArray
                   (Data.Array.Base.STUArray s_as9) GHC.Types.Int (GHC.ST.ST s_as9)
            [LclId]
            $dMArray_aFR =
              Data.Array.Base.$fMArraySTUArrayIntST
                @ s_as9 (GHC.ST.$fMonadST @ s_as9) } in
          GHC.Base.>>=
            @ (GHC.ST.ST s_as9)
            (GHC.ST.$fMonadST @ s_as9)
            @ (Data.Array.Base.STUArray s_as9 GHC.Types.Int GHC.Types.Int)
            @ GHC.Integer.Type.Integer
            (Data.Array.Base.newArray
               @ (Data.Array.Base.STUArray s_as9)
               @ GHC.Types.Int
               @ (GHC.ST.ST s_as9)
               (Data.Array.Base.$fMArraySTUArrayIntST
                  @ s_as9 (GHC.ST.$fMonadST @ s_as9))
               @ GHC.Types.Int
               GHC.Arr.$fIxInt
               (GHC.Types.I# 0,
                GHC.Num.-
                  @ GHC.Types.Int
                  GHC.Num.$fNumInt
                  (GHC.Real.^
                     @ GHC.Types.Int
                     @ GHC.Integer.Type.Integer
                     GHC.Num.$fNumInt
                     GHC.Real.$fIntegralInteger
                     (GHC.Types.I# 10)
                     (__integer 6))
                  (GHC.Types.I# 1))
               (GHC.Types.I# 0))
            (\ (a_apk
                  :: Data.Array.Base.STUArray s_as9 GHC.Types.Int GHC.Types.Int) ->
               GHC.Base.>>
                 @ (GHC.ST.ST s_as9)
                 (GHC.ST.$fMonadST @ s_as9)
                 @ ()
                 @ GHC.Integer.Type.Integer
                 (Control.Monad.forM_
                    @ GHC.Types.Int
                    @ (GHC.ST.ST s_as9)
                    @ ()
                    (GHC.ST.$fMonadST @ s_as9)
                    (GHC.Enum.enumFromTo
                       @ GHC.Types.Int
                       GHC.Enum.$fEnumInt
                       (GHC.Types.I# 0)
                       (GHC.Real.^
                          @ GHC.Types.Int
                          @ GHC.Integer.Type.Integer
                          GHC.Num.$fNumInt
                          GHC.Real.$fIntegralInteger
                          (GHC.Types.I# 10)
                          (__integer 6)))
                    (let {
                       $dMonad_aF0 :: GHC.Base.Monad (GHC.ST.ST s_as9)
                       [LclId]
                       $dMonad_aF0 =
                         Data.Array.Base.$p1MArray
                           @ (Data.Array.Base.STUArray s_as9)
                           @ GHC.Types.Int
                           @ (GHC.ST.ST s_as9)
                           $dMArray_aFR } in
                     \ (i_apm :: GHC.Types.Int) ->
                       GHC.Base.>>=
                         @ (GHC.ST.ST s_as9)
                         $dMonad_aF0
                         @ GHC.Types.Int
                         @ ()
                         (Data.Array.Base.readArray
                            @ (Data.Array.Base.STUArray s_as9)
                            @ GHC.Types.Int
                            @ GHC.Types.Int
                            @ (GHC.ST.ST s_as9)
                            $dMArray_aFR
                            GHC.Arr.$fIxInt
                            a_apk
                            i_apm)
                         (\ (v_apn :: GHC.Types.Int) ->
                            Data.Array.Base.writeArray
                              @ (Data.Array.Base.STUArray s_as9)
                              @ GHC.Types.Int
                              @ GHC.Types.Int
                              @ (GHC.ST.ST s_as9)
                              $dMArray_aFR
                              GHC.Arr.$fIxInt
                              a_apk
                              i_apm
                              (GHC.Num.+
                                 @ GHC.Types.Int GHC.Num.$fNumInt v_apn (GHC.Types.I# 1)))))
                 (GHC.Base.return
                    @ (GHC.ST.ST s_as9)
                    (GHC.ST.$fMonadST @ s_as9)
                    @ GHC.Integer.Type.Integer
                    (__integer 5)))))

:Main.main :: GHC.Types.IO ()
[GblId]
:Main.main = GHC.TopHandler.runMainIO @ () Main.main



Linking a ...
