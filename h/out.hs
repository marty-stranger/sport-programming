[1 of 1] Compiling Main             ( bench-vector-write.hs, bench-vector-write.o )

==================== Tidy Core ====================
Result size of Tidy Core = {terms: 261, types: 220, coercions: 61}

lvl_r2vS :: [GHC.Types.Char]
[GblId]
lvl_r2vS = GHC.CString.unpackCString# "Negative exponent"

Main.$s^1 :: GHC.Types.Int
[GblId, Str=DmdType b]
Main.$s^1 = GHC.Err.error @ GHC.Types.Int lvl_r2vS

lvl1_r2vT :: GHC.Integer.Type.Integer
[GblId, Str=DmdType]
lvl1_r2vT = __integer 1

lvl2_r2vU :: GHC.Integer.Type.Integer
[GblId, Str=DmdType]
lvl2_r2vU = __integer 2

Rec {
$wg1_r2vV
  :: GHC.Prim.Int#
     -> GHC.Integer.Type.Integer -> GHC.Prim.Int# -> GHC.Prim.Int#
[GblId, Arity=3, Str=DmdType LSL]
$wg1_r2vV =
  \ (ww_s2s3 :: GHC.Prim.Int#)
    (w_s2s5 :: GHC.Integer.Type.Integer)
    (ww1_s2s8 :: GHC.Prim.Int#) ->
    case GHC.Integer.Type.eqInteger
           (GHC.Integer.Type.remInteger w_s2s5 GHC.Real.even2) GHC.Real.even1
    of _ {
      GHC.Types.False ->
        case GHC.Integer.Type.eqInteger w_s2s5 lvl1_r2vT of _ {
          GHC.Types.False ->
            $wg1_r2vV
              (GHC.Prim.*# ww_s2s3 ww_s2s3)
              (GHC.Integer.Type.quotInteger
                 (GHC.Integer.Type.minusInteger w_s2s5 lvl1_r2vT) lvl2_r2vU)
              (GHC.Prim.*# ww_s2s3 ww1_s2s8);
          GHC.Types.True -> GHC.Prim.*# ww_s2s3 ww1_s2s8
        };
      GHC.Types.True ->
        $wg1_r2vV
          (GHC.Prim.*# ww_s2s3 ww_s2s3)
          (GHC.Integer.Type.quotInteger w_s2s5 lvl2_r2vU)
          ww1_s2s8
    }
end Rec }

Rec {
Main.$wf [Occ=LoopBreaker]
  :: GHC.Prim.Int# -> GHC.Integer.Type.Integer -> GHC.Prim.Int#
[GblId, Arity=2, Str=DmdType LS]
Main.$wf =
  \ (ww_s2si :: GHC.Prim.Int#)
    (w_s2sk :: GHC.Integer.Type.Integer) ->
    case GHC.Integer.Type.eqInteger
           (GHC.Integer.Type.remInteger w_s2sk GHC.Real.even2) GHC.Real.even1
    of _ {
      GHC.Types.False ->
        case GHC.Integer.Type.eqInteger w_s2sk lvl1_r2vT of _ {
          GHC.Types.False ->
            $wg1_r2vV
              (GHC.Prim.*# ww_s2si ww_s2si)
              (GHC.Integer.Type.quotInteger
                 (GHC.Integer.Type.minusInteger w_s2sk lvl1_r2vT) lvl2_r2vU)
              ww_s2si;
          GHC.Types.True -> ww_s2si
        };
      GHC.Types.True ->
        Main.$wf
          (GHC.Prim.*# ww_s2si ww_s2si)
          (GHC.Integer.Type.quotInteger w_s2sk lvl2_r2vU)
    }
end Rec }

Main.$s^2 :: GHC.Integer.Type.Integer
[GblId,
 Str=DmdType,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=True,
         ConLike=True, WorkFree=True, Expandable=True,
         Guidance=IF_ARGS [] 100 0}]
Main.$s^2 = __integer 0

Main.$w$s^
  :: GHC.Types.Int -> GHC.Integer.Type.Integer -> GHC.Prim.Int#
[GblId,
 Arity=2,
 Str=DmdType LS,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=2, Value=True,
         ConLike=True, WorkFree=True, Expandable=True,
         Guidance=IF_ARGS [20 0] 140 0}]
Main.$w$s^ =
  \ (w_s2sr :: GHC.Types.Int)
    (w1_s2ss :: GHC.Integer.Type.Integer) ->
    case GHC.Integer.Type.ltInteger w1_s2ss Main.$s^2 of _ {
      GHC.Types.False ->
        case GHC.Integer.Type.eqInteger w1_s2ss Main.$s^2 of _ {
          GHC.Types.False ->
            case w_s2sr of _ { GHC.Types.I# ww_s2si ->
            Main.$wf ww_s2si w1_s2ss
            };
          GHC.Types.True -> 1
        };
      GHC.Types.True -> case Main.$s^1 of wild1_00 { }
    }

Main.$s^ [InlPrag=INLINE[0]]
  :: GHC.Types.Int -> GHC.Integer.Type.Integer -> GHC.Types.Int
[GblId,
 Arity=2,
 Str=DmdType LSm,
 Unf=Unf{Src=Worker=Main.$w$s^, TopLvl=True, Arity=2, Value=True,
         ConLike=True, WorkFree=True, Expandable=True,
         Guidance=ALWAYS_IF(unsat_ok=True,boring_ok=False)
         Tmpl= \ (w_s2sr [Occ=Once] :: GHC.Types.Int)
                 (w1_s2ss [Occ=Once] :: GHC.Integer.Type.Integer) ->
                 case Main.$w$s^ w_s2sr w1_s2ss of ww_s2sv { __DEFAULT ->
                 GHC.Types.I# ww_s2sv
                 }}]
Main.$s^ =
  \ (w_s2sr :: GHC.Types.Int)
    (w1_s2ss :: GHC.Integer.Type.Integer) ->
    case Main.$w$s^ w_s2sr w1_s2ss of ww_s2sv { __DEFAULT ->
    GHC.Types.I# ww_s2sv
    }

Main.main9 :: GHC.Types.Int
[GblId,
 Caf=NoCafRefs,
 Str=DmdType m,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=True,
         ConLike=True, WorkFree=False, Expandable=True,
         Guidance=IF_ARGS [] 10 20}]
Main.main9 = GHC.Types.I# 10

Main.main8 :: GHC.Integer.Type.Integer
[GblId,
 Str=DmdType,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=True,
         ConLike=True, WorkFree=True, Expandable=True,
         Guidance=IF_ARGS [] 100 0}]
Main.main8 = __integer 6

Main.main11 :: GHC.Types.Int
[GblId,
 Str=DmdType,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=False,
         ConLike=False, WorkFree=False, Expandable=False,
         Guidance=IF_ARGS [] 50 20}]
Main.main11 =
  scc<f>
  scc<f.l>
  case Main.$w$s^ Main.main9 Main.main8 of ww_s2sv { __DEFAULT ->
  GHC.Types.I# ww_s2sv
  }

Main.main7 :: GHC.Types.Int
[GblId,
 Str=DmdType,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=False,
         ConLike=False, WorkFree=False, Expandable=False,
         Guidance=IF_ARGS [] 50 20}]
Main.main7 =
  scc<f>
  case Main.$w$s^ Main.main9 Main.main8 of ww_s2sv { __DEFAULT ->
  GHC.Types.I# ww_s2sv
  }

Main.main6 :: GHC.Types.Int
[GblId,
 Str=DmdType,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=False,
         ConLike=False, WorkFree=False, Expandable=True,
         Guidance=IF_ARGS [] 21 20}]
Main.main6 =
  scc<f>
  case Main.main7 of _ { GHC.Types.I# x_a15W ->
  GHC.Types.I# (GHC.Prim.-# x_a15W 10)
  }

Main.main4 :: GHC.Integer.Type.Integer
[GblId,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=True,
         ConLike=True, WorkFree=True, Expandable=True,
         Guidance=IF_ARGS [] 100 0}]
Main.main4 = __integer 5

Main.main5 :: [GHC.Types.Int]
[GblId,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=False,
         ConLike=False, WorkFree=False, Expandable=False,
         Guidance=IF_ARGS [] 40 0}]
Main.main5 =
  scc<f>
  case Main.main6 of _ { GHC.Types.I# y_a16e ->
  GHC.Enum.eftInt 0 y_a16e
  }

lvl3_r2vW :: [GHC.Types.Char]
[GblId]
lvl3_r2vW =
  scc<f>
  GHC.CString.unpackCString# "./Data/Vector/Generic/Mutable.hs"

lvl4_r2vX :: GHC.Types.Int
[GblId, Caf=NoCafRefs]
lvl4_r2vX = GHC.Types.I# 494

lvl5_r2vY :: [GHC.Types.Char]
[GblId]
lvl5_r2vY = scc<f> GHC.CString.unpackCString# "new"

Main.main10
  :: forall s_XLH.
     GHC.Prim.Int#
     -> GHC.ST.ST
          s_XLH
          (Data.Vector.Unboxed.Base.MVector
             (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))
             GHC.Word.Word64)
[GblId, Arity=1, Str=DmdType Tb]
Main.main10 =
  \ (@ s_XLH) (x1_a1av :: GHC.Prim.Int#) ->
    Data.Vector.Internal.Check.checkError
      @ (GHC.ST.ST
           s_XLH
           (Data.Vector.Unboxed.Base.MVector
              (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))
              GHC.Word.Word64))
      lvl3_r2vW
      lvl4_r2vX
      Data.Vector.Internal.Check.Bounds
      lvl5_r2vY
      (Data.Vector.Internal.Check.checkLength_msg# x1_a1av)

Main.main3
  :: forall s_XLH.
     GHC.Prim.State# s_XLH
     -> (# GHC.Prim.State# s_XLH, GHC.Integer.Type.Integer #)
[GblId,
 Arity=1,
 Str=DmdType L,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=1, Value=True,
         ConLike=True, WorkFree=True, Expandable=True,
         Guidance=IF_ARGS [0] 259 30}]
Main.main3 =
  \ (@ s_XLH) (s_X18J :: GHC.Prim.State# s_XLH) ->
    case (scc<f>
          tick<f.l>
          case Main.main11 of _ { GHC.Types.I# x1_a1av ->
          case GHC.Prim.>=# x1_a1av 0 of _ {
            GHC.Types.False ->
              (Main.main10 @ s_XLH x1_a1av)
              `cast` (<GHC.ST.NTCo:ST
                         <s_XLH>
                         (Data.Vector.Unboxed.Base.MVector
                            <(Control.Monad.Primitive.TFCo:R:PrimStateST <s_XLH>)>
                            <GHC.Word.Word64>)>
                      :: GHC.ST.ST
                           s_XLH
                           (Data.Vector.Unboxed.Base.MVector
                              (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))
                              GHC.Word.Word64)
                           ~#
                         GHC.ST.STRep
                           s_XLH (Data.Vector.Unboxed.Base.MVector s_XLH GHC.Word.Word64));
            GHC.Types.True ->
              (\ (s1_a16O :: GHC.Prim.State# s_XLH) ->
                 case GHC.Prim.newByteArray#
                        @ (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))
                        (GHC.Prim.*# x1_a1av 8)
                        (s1_a16O
                         `cast` (GHC.Prim.State#
                                   (Sym <(Control.Monad.Primitive.TFCo:R:PrimStateST <s_XLH>)>)
                                 :: GHC.Prim.State# s_XLH
                                      ~#
                                    GHC.Prim.State#
                                      (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))))
                 of _ { (# ipv_a1gL, ipv1_a1gM #) ->
                 (# ipv_a1gL
                    `cast` (GHC.Prim.State#
                              <(Control.Monad.Primitive.TFCo:R:PrimStateST <s_XLH>)>
                            :: GHC.Prim.State#
                                 (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))
                                 ~#
                               GHC.Prim.State# s_XLH),
                    (Data.Vector.Primitive.Mutable.MVector
                       @ (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))
                       @ GHC.Word.Word64
                       0
                       x1_a1av
                       ipv1_a1gM)
                    `cast` (Sym
                              <(Data.Vector.Unboxed.Base.NTCo:R:MVectorsWord64
                                  <Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH)>)> ; Sym
                                                                                              <(Data.Vector.Unboxed.Base.TFCo:R:MVectorsWord64
                                                                                                  <Control.Monad.Primitive.PrimState
                                                                                                     (GHC.ST.ST
                                                                                                        s_XLH)>)>
                            :: Data.Vector.Primitive.Mutable.MVector
                                 (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))
                                 GHC.Word.Word64
                                 ~#
                               Data.Vector.Unboxed.Base.MVector
                                 (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))
                                 GHC.Word.Word64) #)
                 })
              `cast` (<GHC.Prim.State# s_XLH>
                      -> (# <GHC.Prim.State# s_XLH>,
                            Data.Vector.Unboxed.Base.MVector
                              <(Control.Monad.Primitive.TFCo:R:PrimStateST <s_XLH>)>
                              <GHC.Word.Word64> #)
                      :: (GHC.Prim.State# s_XLH
                          -> (# GHC.Prim.State# s_XLH,
                                Data.Vector.Unboxed.Base.MVector
                                  (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))
                                  GHC.Word.Word64 #))
                           ~#
                         (GHC.Prim.State# s_XLH
                          -> (# GHC.Prim.State# s_XLH,
                                Data.Vector.Unboxed.Base.MVector s_XLH GHC.Word.Word64 #)))
          }
          })
           s_X18J
    of _ { (# ipv_a16R, ipv1_a16S #) ->
    letrec {
      a_s2rj [Occ=LoopBreaker]
        :: [GHC.Types.Int]
           -> GHC.Prim.State# s_XLH -> (# GHC.Prim.State# s_XLH, () #)
      [LclId, Arity=2, Str=DmdType SL]
      a_s2rj =
        \ (ds_a1iC :: [GHC.Types.Int]) (eta_B1 :: GHC.Prim.State# s_XLH) ->
          case ds_a1iC of _ {
            [] -> (# eta_B1, GHC.Tuple.() #);
            : y_a1iH ys_a1iI ->
              case (scctick<f.\>
                    case ipv1_a16S
                         `cast` (<Data.Vector.Unboxed.Base.TFCo:R:MVectorsWord64
                                    (Sym
                                       <(Control.Monad.Primitive.TFCo:R:PrimStateST
                                           <s_XLH>)>)> ; <Data.Vector.Unboxed.Base.NTCo:R:MVectorsWord64
                                                            <Control.Monad.Primitive.PrimState
                                                               (GHC.ST.ST s_XLH)>>
                                 :: Data.Vector.Unboxed.Base.MVector s_XLH GHC.Word.Word64
                                      ~#
                                    Data.Vector.Primitive.Mutable.MVector
                                      (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))
                                      GHC.Word.Word64)
                    of _ { Data.Vector.Primitive.Mutable.MVector rb_a1jz _ rb2_a1jB ->
                    case y_a1iH of _ { GHC.Types.I# y1_a1jR ->
                    (\ (s#_a1jH
                          :: GHC.Prim.State#
                               (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))) ->
                       (# GHC.Prim.writeWord64Array#
                            @ (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))
                            rb2_a1jB
                            (GHC.Prim.+# rb_a1jz y1_a1jR)
                            (__word 3)
                            s#_a1jH,
                          GHC.Tuple.() #))
                    `cast` (GHC.Prim.State#
                              <(Control.Monad.Primitive.TFCo:R:PrimStateST <s_XLH>)>
                            -> (# GHC.Prim.State#
                                    <(Control.Monad.Primitive.TFCo:R:PrimStateST <s_XLH>)>,
                                  <()> #)
                            :: (GHC.Prim.State#
                                  (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH))
                                -> (# GHC.Prim.State#
                                        (Control.Monad.Primitive.PrimState (GHC.ST.ST s_XLH)),
                                      () #))
                                 ~#
                               (GHC.Prim.State# s_XLH -> (# GHC.Prim.State# s_XLH, () #)))
                    }
                    })
                     eta_B1
              of _ { (# ipv2_a16D, _ #) ->
              a_s2rj ys_a1iI ipv2_a16D
              }
          }; } in
    case a_s2rj Main.main5 ipv_a16R of _ { (# ipv2_a16D, _ #) ->
    (# ipv2_a16D, Main.main4 #)
    }
    }

Main.f :: GHC.Integer.Type.Integer
[GblId,
 Str=DmdType,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=False,
         ConLike=False, WorkFree=False, Expandable=False,
         Guidance=IF_ARGS [] 20 0}]
Main.f =
  scctick<f> GHC.ST.runSTRep @ GHC.Integer.Type.Integer Main.main3

Main.main2 :: GHC.Base.String
[GblId,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=False,
         ConLike=False, WorkFree=False, Expandable=False,
         Guidance=IF_ARGS [] 20 0}]
Main.main2 = scc<main> GHC.Show.$fShowInteger_$cshow Main.f

Main.main1
  :: GHC.Prim.State# GHC.Prim.RealWorld
     -> (# GHC.Prim.State# GHC.Prim.RealWorld, () #)
[GblId,
 Str=DmdType,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=False,
         ConLike=False, WorkFree=False, Expandable=False,
         Guidance=IF_ARGS [] 60 60}]
Main.main1 =
  tick<main>
  \ (eta_a1kg :: GHC.Prim.State# GHC.Prim.RealWorld) ->
    scc<main>
    GHC.IO.Handle.Text.hPutStr2
      GHC.IO.Handle.FD.stdout Main.main2 GHC.Types.True eta_a1kg

Main.main :: GHC.Types.IO ()
[GblId,
 Str=DmdType,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=False,
         ConLike=False, WorkFree=True, Expandable=True,
         Guidance=ALWAYS_IF(unsat_ok=True,boring_ok=True)}]
Main.main =
  Main.main1
  `cast` (Sym <(GHC.Types.NTCo:IO <()>)>
          :: (GHC.Prim.State# GHC.Prim.RealWorld
              -> (# GHC.Prim.State# GHC.Prim.RealWorld, () #))
               ~#
             GHC.Types.IO ())

Main.main12
  :: GHC.Prim.State# GHC.Prim.RealWorld
     -> (# GHC.Prim.State# GHC.Prim.RealWorld, () #)
[GblId,
 Arity=1,
 Str=DmdType L,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=1, Value=True,
         ConLike=True, WorkFree=True, Expandable=True,
         Guidance=IF_ARGS [0] 30 0}]
Main.main12 =
  \ (eta_B1 :: GHC.Prim.State# GHC.Prim.RealWorld) ->
    GHC.TopHandler.runMainIO1
      @ ()
      (Main.main1
       `cast` (Sym <(GHC.Types.NTCo:IO <()>)>
               :: (GHC.Prim.State# GHC.Prim.RealWorld
                   -> (# GHC.Prim.State# GHC.Prim.RealWorld, () #))
                    ~#
                  GHC.Types.IO ()))
      eta_B1

:Main.main :: GHC.Types.IO ()
[GblId,
 Arity=1,
 Str=DmdType L,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=True,
         ConLike=True, WorkFree=True, Expandable=True,
         Guidance=ALWAYS_IF(unsat_ok=True,boring_ok=True)}]
:Main.main =
  Main.main12
  `cast` (Sym <(GHC.Types.NTCo:IO <()>)>
          :: (GHC.Prim.State# GHC.Prim.RealWorld
              -> (# GHC.Prim.State# GHC.Prim.RealWorld, () #))
               ~#
             GHC.Types.IO ())


------ Local rules for imported ids --------
"SPEC GHC.Real.^ [GHC.Types.Int, GHC.Integer.Type.Integer]" [ALWAYS]
    forall ($dNum_s17d :: GHC.Num.Num GHC.Types.Int)
           ($dIntegral_s17f :: GHC.Real.Integral GHC.Integer.Type.Integer).
      GHC.Real.^ @ GHC.Types.Int
                 @ GHC.Integer.Type.Integer
                 $dNum_s17d
                 $dIntegral_s17f
      = Main.$s^


Linking bench-vector-write ...
