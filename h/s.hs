[1 of 1] Compiling Main             ( b.hs, b.o )

==================== Tidy Core ====================
Result size of Tidy Core = {terms: 614, types: 467, coercions: 60}

lvl_r2Jp :: [GHC.Types.Char]
[GblId]
lvl_r2Jp = GHC.CString.unpackCString# "Negative exponent"

Main.$s^1 :: GHC.Types.Int
[GblId, Str=DmdType b]
Main.$s^1 = GHC.Err.error @ GHC.Types.Int lvl_r2Jp

lvl1_r2Jq :: GHC.Integer.Type.Integer
[GblId, Str=DmdType]
lvl1_r2Jq = __integer 1

lvl2_r2Jr :: GHC.Integer.Type.Integer
[GblId, Str=DmdType]
lvl2_r2Jr = __integer 2

Rec {
$wg1_r2Js
  :: GHC.Prim.Int#
     -> GHC.Integer.Type.Integer -> GHC.Prim.Int# -> GHC.Prim.Int#
[GblId, Arity=3, Str=DmdType LSL]
$wg1_r2Js =
  \ (ww_s2AS :: GHC.Prim.Int#)
    (w_s2AU :: GHC.Integer.Type.Integer)
    (ww1_s2AX :: GHC.Prim.Int#) ->
    case GHC.Integer.Type.eqInteger
           (GHC.Integer.Type.remInteger w_s2AU GHC.Real.even2) GHC.Real.even1
    of _ {
      GHC.Types.False ->
        case GHC.Integer.Type.eqInteger w_s2AU lvl1_r2Jq of _ {
          GHC.Types.False ->
            $wg1_r2Js
              (GHC.Prim.*# ww_s2AS ww_s2AS)
              (GHC.Integer.Type.quotInteger
                 (GHC.Integer.Type.minusInteger w_s2AU lvl1_r2Jq) lvl2_r2Jr)
              (GHC.Prim.*# ww_s2AS ww1_s2AX);
          GHC.Types.True -> GHC.Prim.*# ww_s2AS ww1_s2AX
        };
      GHC.Types.True ->
        $wg1_r2Js
          (GHC.Prim.*# ww_s2AS ww_s2AS)
          (GHC.Integer.Type.quotInteger w_s2AU lvl2_r2Jr)
          ww1_s2AX
    }
end Rec }

Rec {
Main.$wf [Occ=LoopBreaker]
  :: GHC.Prim.Int# -> GHC.Integer.Type.Integer -> GHC.Prim.Int#
[GblId, Arity=2, Str=DmdType LS]
Main.$wf =
  \ (ww_s2B7 :: GHC.Prim.Int#)
    (w_s2B9 :: GHC.Integer.Type.Integer) ->
    case GHC.Integer.Type.eqInteger
           (GHC.Integer.Type.remInteger w_s2B9 GHC.Real.even2) GHC.Real.even1
    of _ {
      GHC.Types.False ->
        case GHC.Integer.Type.eqInteger w_s2B9 lvl1_r2Jq of _ {
          GHC.Types.False ->
            $wg1_r2Js
              (GHC.Prim.*# ww_s2B7 ww_s2B7)
              (GHC.Integer.Type.quotInteger
                 (GHC.Integer.Type.minusInteger w_s2B9 lvl1_r2Jq) lvl2_r2Jr)
              ww_s2B7;
          GHC.Types.True -> ww_s2B7
        };
      GHC.Types.True ->
        Main.$wf
          (GHC.Prim.*# ww_s2B7 ww_s2B7)
          (GHC.Integer.Type.quotInteger w_s2B9 lvl2_r2Jr)
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
  \ (w_s2Bg :: GHC.Types.Int)
    (w1_s2Bh :: GHC.Integer.Type.Integer) ->
    case GHC.Integer.Type.ltInteger w1_s2Bh Main.$s^2 of _ {
      GHC.Types.False ->
        case GHC.Integer.Type.eqInteger w1_s2Bh Main.$s^2 of _ {
          GHC.Types.False ->
            case w_s2Bg of _ { GHC.Types.I# ww_s2B7 ->
            Main.$wf ww_s2B7 w1_s2Bh
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
         Tmpl= \ (w_s2Bg [Occ=Once] :: GHC.Types.Int)
                 (w1_s2Bh [Occ=Once] :: GHC.Integer.Type.Integer) ->
                 case Main.$w$s^ w_s2Bg w1_s2Bh of ww_s2Bk { __DEFAULT ->
                 GHC.Types.I# ww_s2Bk
                 }}]
Main.$s^ =
  \ (w_s2Bg :: GHC.Types.Int)
    (w1_s2Bh :: GHC.Integer.Type.Integer) ->
    case Main.$w$s^ w_s2Bg w1_s2Bh of ww_s2Bk { __DEFAULT ->
    GHC.Types.I# ww_s2Bk
    }

lvl3_r2Jt :: GHC.Types.Int
[GblId, Caf=NoCafRefs, Str=DmdType m]
lvl3_r2Jt = GHC.Types.I# 10

lvl4_r2Ju :: GHC.Integer.Type.Integer
[GblId, Str=DmdType]
lvl4_r2Ju = __integer 6

lvl5_r2Jv :: GHC.Types.Int
[GblId, Str=DmdType]
lvl5_r2Jv =
  scc<update>
  case Main.$w$s^ lvl3_r2Jt lvl4_r2Ju of ww_s2Bk { __DEFAULT ->
  GHC.Types.I# ww_s2Bk
  }

lvl6_r2Jw :: GHC.Types.Int
[GblId, Str=DmdType]
lvl6_r2Jw =
  scc<update>
  case Main.$w$s^ lvl3_r2Jt lvl4_r2Ju of ww_s2Bk { __DEFAULT ->
  GHC.Types.I# ww_s2Bk
  }

lvl7_r2Jx :: GHC.Integer.Type.Integer
[GblId, Str=DmdType]
lvl7_r2Jx = __integer 8

lvl8_r2Jy :: GHC.Types.Int
[GblId, Str=DmdType]
lvl8_r2Jy =
  scc<update>
  case Main.$w$s^ lvl3_r2Jt lvl7_r2Jx of ww_s2Bk { __DEFAULT ->
  GHC.Types.I# ww_s2Bk
  }

lvl9_r2Jz :: GHC.Types.Int
[GblId, Str=DmdType]
lvl9_r2Jz =
  scc<update>
  case lvl8_r2Jy of _ { GHC.Types.I# x_aZ2 ->
  GHC.Types.I# (GHC.Prim.-# x_aZ2 1)
  }

lvl10_r2JA :: [GHC.Types.Char]
[GblId]
lvl10_r2JA =
  GHC.CString.unpackCString# "./Data/Vector/Generic/Mutable.hs"

lvl11_r2JB :: GHC.Types.Int
[GblId, Caf=NoCafRefs]
lvl11_r2JB = GHC.Types.I# 494

lvl12_r2JC :: [GHC.Types.Char]
[GblId]
lvl12_r2JC = GHC.CString.unpackCString# "new"

file_r2JD :: GHC.Base.String
[GblId, Str=DmdType]
file_r2JD =
  scc<update>
  GHC.CString.unpackCString# "./Data/Vector/Generic/Mutable.hs"

lvl13_r2JE :: GHC.Types.Int
[GblId, Caf=NoCafRefs]
lvl13_r2JE = GHC.Types.I# 596

lvl14_r2JF :: [GHC.Types.Char]
[GblId]
lvl14_r2JF = scc<update> GHC.CString.unpackCString# "write"

lvl15_r2JG
  :: forall s_aIe.
     GHC.Prim.Int# -> GHC.Prim.Int# -> GHC.ST.ST s_aIe ()
[GblId, Arity=2, Str=DmdType TTb]
lvl15_r2JG =
  \ (@ s_aIe)
    (x1_a1iN :: GHC.Prim.Int#)
    (x2_a1rr :: GHC.Prim.Int#) ->
    Data.Vector.Internal.Check.checkError
      @ (GHC.ST.ST s_aIe ())
      file_r2JD
      lvl13_r2JE
      Data.Vector.Internal.Check.Bounds
      lvl14_r2JF
      (Data.Vector.Internal.Check.checkIndex_msg# x2_a1rr x1_a1iN)

lvl16_r2JH
  :: forall s_aIe.
     GHC.Prim.Int# -> GHC.Prim.Int# -> GHC.ST.ST s_aIe ()
[GblId, Arity=2, Str=DmdType TTb]
lvl16_r2JH =
  \ (@ s_aIe)
    (x1_a1iN :: GHC.Prim.Int#)
    (x2_a1rr :: GHC.Prim.Int#) ->
    Data.Vector.Internal.Check.checkError
      @ (GHC.ST.ST s_aIe ())
      file_r2JD
      lvl13_r2JE
      Data.Vector.Internal.Check.Bounds
      lvl14_r2JF
      (Data.Vector.Internal.Check.checkIndex_msg# x2_a1rr x1_a1iN)

lvl17_r2JI
  :: forall s_aIe.
     GHC.Prim.Int# -> GHC.Prim.Int# -> GHC.ST.ST s_aIe ()
[GblId, Arity=2, Str=DmdType TTb]
lvl17_r2JI =
  \ (@ s_aIe)
    (x1_X1tE :: GHC.Prim.Int#)
    (x2_a1iN :: GHC.Prim.Int#) ->
    Data.Vector.Internal.Check.checkError
      @ (GHC.ST.ST s_aIe ())
      file_r2JD
      lvl13_r2JE
      Data.Vector.Internal.Check.Bounds
      lvl14_r2JF
      (Data.Vector.Internal.Check.checkIndex_msg# x1_X1tE x2_a1iN)

lvl18_r2JJ
  :: forall s_aIe.
     GHC.Prim.Int# -> GHC.Prim.Int# -> GHC.ST.ST s_aIe ()
[GblId, Arity=2, Str=DmdType TTb]
lvl18_r2JJ =
  \ (@ s_aIe)
    (x1_X1tE :: GHC.Prim.Int#)
    (x2_a1iN :: GHC.Prim.Int#) ->
    Data.Vector.Internal.Check.checkError
      @ (GHC.ST.ST s_aIe ())
      file_r2JD
      lvl13_r2JE
      Data.Vector.Internal.Check.Bounds
      lvl14_r2JF
      (Data.Vector.Internal.Check.checkIndex_msg# x1_X1tE x2_a1iN)

lvl19_r2JK :: GHC.Types.Int
[GblId, Caf=NoCafRefs]
lvl19_r2JK = GHC.Types.I# 0

lvl20_r2JL :: [GHC.Types.Char]
[GblId]
lvl20_r2JL = GHC.CString.unpackCString# "write"

lvl21_r2JM
  :: forall s_aIe.
     GHC.Prim.Int# -> GHC.Prim.Int# -> GHC.ST.ST s_aIe ()
[GblId, Arity=2, Str=DmdType TTb]
lvl21_r2JM =
  \ (@ s_aIe) (x_a15x :: GHC.Prim.Int#) (x1_a1iN :: GHC.Prim.Int#) ->
    Data.Vector.Internal.Check.checkError
      @ (GHC.ST.ST s_aIe ())
      lvl10_r2JA
      lvl13_r2JE
      Data.Vector.Internal.Check.Bounds
      lvl20_r2JL
      (Data.Vector.Internal.Check.checkIndex_msg# x_a15x x1_a1iN)

lvl22_r2JN
  :: forall s_aIe.
     GHC.Prim.Int# -> GHC.Prim.Int# -> GHC.ST.ST s_aIe ()
[GblId, Arity=2, Str=DmdType TTb]
lvl22_r2JN =
  \ (@ s_aIe) (x_a15x :: GHC.Prim.Int#) (x1_a1iN :: GHC.Prim.Int#) ->
    Data.Vector.Internal.Check.checkError
      @ (GHC.ST.ST s_aIe ())
      lvl10_r2JA
      lvl13_r2JE
      Data.Vector.Internal.Check.Bounds
      lvl20_r2JL
      (Data.Vector.Internal.Check.checkIndex_msg# x_a15x x1_a1iN)

Main.main3
  :: forall s_aIe.
     GHC.Prim.State# s_aIe -> (# GHC.Prim.State# s_aIe, GHC.Types.Int #)
[GblId, Arity=1]
Main.main3 =
  \ (@ s_aIe) (s_a10O :: GHC.Prim.State# s_aIe) ->
    case Main.$w$s^ lvl3_r2Jt lvl4_r2Ju of ww_s2Bk { __DEFAULT ->
    let {
      x1_a1iN [Dmd=Just L] :: GHC.Prim.Int#
      [LclId, Str=DmdType]
      x1_a1iN = GHC.Prim.+# ww_s2Bk 100 } in
    case GHC.Prim.>=# x1_a1iN 0 of _ {
      GHC.Types.False ->
        case Data.Vector.Internal.Check.checkError
               @ (GHC.ST.ST
                    s_aIe
                    (Data.Vector.Unboxed.Base.MVector
                       (Control.Monad.Primitive.PrimState (GHC.ST.ST s_aIe))
                       GHC.Types.Int))
               lvl10_r2JA
               lvl11_r2JB
               Data.Vector.Internal.Check.Bounds
               lvl12_r2JC
               (Data.Vector.Internal.Check.checkLength_msg# x1_a1iN)
        of wild_00 {
        };
      GHC.Types.True ->
        case GHC.Prim.newByteArray#
               @ (Control.Monad.Primitive.PrimState (GHC.ST.ST s_aIe))
               (GHC.Prim.*# x1_a1iN 8)
               (s_a10O
                `cast` (GHC.Prim.State#
                          (Sym <(Control.Monad.Primitive.TFCo:R:PrimStateST <s_aIe>)>)
                        :: GHC.Prim.State# s_aIe
                             ~#
                           GHC.Prim.State#
                             (Control.Monad.Primitive.PrimState (GHC.ST.ST s_aIe))))
        of _ { (# ipv_a1q6, ipv1_a1q7 #) ->
        case Main.$w$s^ lvl3_r2Jt lvl4_r2Ju of ww1_X2Cx { __DEFAULT ->
        let {
          y_a15t [Dmd=Just L] :: GHC.Prim.Int#
          [LclId, Str=DmdType]
          y_a15t = GHC.Prim.-# ww1_X2Cx 1 } in
        let {
          $j_s2za
            :: GHC.Prim.State# s_aIe
               -> (# GHC.Prim.State# s_aIe, GHC.Types.Int #)
          [LclId, Arity=1, Str=DmdType L]
          $j_s2za =
            \ (ipv2_a10D :: GHC.Prim.State# s_aIe) ->
              (scctick<update>
               let {
                 $wa_s2BC
                   :: GHC.Prim.Int#
                      -> GHC.Prim.State# s_aIe
                      -> (# GHC.Prim.State# s_aIe, GHC.Types.Int #)
                 [LclId, Arity=2, Str=DmdType LL]
                 $wa_s2BC =
                   \ (ww2_s2Bv :: GHC.Prim.Int#) (w_s2Bx :: GHC.Prim.State# s_aIe) ->
                     case ww2_s2Bv of wild_X2S {
                       __DEFAULT ->
                         case lvl5_r2Jv of _ { GHC.Types.I# ww3_aZQ ->
                         let {
                           $w$j_s2BD
                             :: GHC.Prim.Int# -> (# GHC.Prim.State# s_aIe, GHC.Types.Int #)
                           [LclId, Arity=1, Str=DmdType L]
                           $w$j_s2BD =
                             \ (w1_s2Bo :: GHC.Prim.Int#) ->
                               case GHC.Prim.readIntArray#
                                      @ (Control.Monad.Primitive.PrimState (GHC.ST.ST s_aIe))
                                      ipv1_a1q7
                                      w1_s2Bo
                                      (w_s2Bx
                                       `cast` (GHC.Prim.State#
                                                 (Sym
                                                    <(Control.Monad.Primitive.TFCo:R:PrimStateST
                                                        <s_aIe>)>)
                                               :: GHC.Prim.State# s_aIe
                                                    ~#
                                                  GHC.Prim.State#
                                                    (Control.Monad.Primitive.PrimState
                                                       (GHC.ST.ST s_aIe))))
                               of _ { (# ipv3_a1tb, ipv4_a1tc #) ->
                               case lvl6_r2Jw of _ { GHC.Types.I# ww4_X11K ->
                               let {
                                 $j1_s2ys
                                   :: GHC.Prim.Int# -> (# GHC.Prim.State# s_aIe, GHC.Types.Int #)
                                 [LclId, Arity=1, Str=DmdType L]
                                 $j1_s2ys =
                                   \ (y1_X12n :: GHC.Prim.Int#) ->
                                     case GHC.Prim.readIntArray#
                                            @ (Control.Monad.Primitive.PrimState (GHC.ST.ST s_aIe))
                                            ipv1_a1q7
                                            y1_X12n
                                            ipv3_a1tb
                                     of _ { (# ipv5_X1wQ, ipv6_X1wS #) ->
                                     case GHC.Prim.<# ipv4_a1tc 100000000000 of _ {
                                       GHC.Types.False ->
                                         (# ipv5_X1wQ
                                            `cast` (GHC.Prim.State#
                                                      <(Control.Monad.Primitive.TFCo:R:PrimStateST
                                                          <s_aIe>)>
                                                    :: GHC.Prim.State#
                                                         (Control.Monad.Primitive.PrimState
                                                            (GHC.ST.ST s_aIe))
                                                         ~#
                                                       GHC.Prim.State# s_aIe),
                                            GHC.Types.I# wild_X2S #);
                                       GHC.Types.True ->
                                         case GHC.Classes.divInt# w1_s2Bo 2
                                         of ww5_a2xE { __DEFAULT ->
                                         let {
                                           x2_a1rr [Dmd=Just L] :: GHC.Prim.Int#
                                           [LclId, Str=DmdType]
                                           x2_a1rr = GHC.Prim.+# ww5_a2xE 1 } in
                                         case GHC.Prim.>=# x2_a1rr 0 of _ {
                                           GHC.Types.False ->
                                             case lvl15_r2JG @ s_aIe x1_a1iN x2_a1rr of wild4_00 {
                                             };
                                           GHC.Types.True ->
                                             case GHC.Prim.<# x2_a1rr x1_a1iN of _ {
                                               GHC.Types.False ->
                                                 case lvl16_r2JH @ s_aIe x1_a1iN x2_a1rr
                                                 of wild5_00 {
                                                 };
                                               GHC.Types.True ->
                                                 case (GHC.Prim.writeIntArray#
                                                         @ (Control.Monad.Primitive.PrimState
                                                              (GHC.ST.ST s_aIe))
                                                         ipv1_a1q7
                                                         x2_a1rr
                                                         (GHC.Prim.+# ipv6_X1wS 1)
                                                         ipv5_X1wQ)
                                                      `cast` (GHC.Prim.State#
                                                                <(Control.Monad.Primitive.TFCo:R:PrimStateST
                                                                    <s_aIe>)>
                                                              :: GHC.Prim.State#
                                                                   (Control.Monad.Primitive.PrimState
                                                                      (GHC.ST.ST s_aIe))
                                                                   ~#
                                                                 GHC.Prim.State# s_aIe)
                                                 of ipv7_X14A { __DEFAULT ->
                                                 case GHC.Prim.>=# x2_a1rr 0 of _ {
                                                   GHC.Types.False ->
                                                     case lvl17_r2JI @ s_aIe x2_a1rr x1_a1iN
                                                     of wild6_00 {
                                                     };
                                                   GHC.Types.True ->
                                                     case GHC.Prim.<# x2_a1rr x1_a1iN of _ {
                                                       GHC.Types.False ->
                                                         case lvl18_r2JJ @ s_aIe x2_a1rr x1_a1iN
                                                         of wild7_00 {
                                                         };
                                                       GHC.Types.True ->
                                                         case (GHC.Prim.writeIntArray#
                                                                 @ (Control.Monad.Primitive.PrimState
                                                                      (GHC.ST.ST s_aIe))
                                                                 ipv1_a1q7
                                                                 x2_a1rr
                                                                 (GHC.Prim.+# ipv4_a1tc 1)
                                                                 (ipv7_X14A
                                                                  `cast` (GHC.Prim.State#
                                                                            (Sym
                                                                               <(Control.Monad.Primitive.TFCo:R:PrimStateST
                                                                                   <s_aIe>)>)
                                                                          :: GHC.Prim.State# s_aIe
                                                                               ~#
                                                                             GHC.Prim.State#
                                                                               (Control.Monad.Primitive.PrimState
                                                                                  (GHC.ST.ST
                                                                                     s_aIe)))))
                                                              `cast` (GHC.Prim.State#
                                                                        <(Control.Monad.Primitive.TFCo:R:PrimStateST
                                                                            <s_aIe>)>
                                                                      :: GHC.Prim.State#
                                                                           (Control.Monad.Primitive.PrimState
                                                                              (GHC.ST.ST s_aIe))
                                                                           ~#
                                                                         GHC.Prim.State# s_aIe)
                                                         of ipv8_X14f { __DEFAULT ->
                                                         letrec {
                                                           $wa1_X2Ez [Occ=LoopBreaker]
                                                             :: GHC.Prim.Int#
                                                                -> GHC.Prim.State# s_aIe
                                                                -> (# GHC.Prim.State# s_aIe,
                                                                      GHC.Types.Int #)
                                                           [LclId, Arity=2, Str=DmdType LL]
                                                           $wa1_X2Ez =
                                                             \ (ww6_X2Et :: GHC.Prim.Int#)
                                                               (w4_X2Ew :: GHC.Prim.State# s_aIe) ->
                                                               case ww6_X2Et of wild7_X5S {
                                                                 __DEFAULT ->
                                                                   let {
                                                                     $w$j1_X2EI
                                                                       :: GHC.Prim.Int#
                                                                          -> (# GHC.Prim.State#
                                                                                  s_aIe,
                                                                                GHC.Types.Int #)
                                                                     [LclId, Arity=1, Str=DmdType L]
                                                                     $w$j1_X2EI =
                                                                       \ (w5_X2Eu
                                                                            :: GHC.Prim.Int#) ->
                                                                         case GHC.Prim.readIntArray#
                                                                                @ (Control.Monad.Primitive.PrimState
                                                                                     (GHC.ST.ST
                                                                                        s_aIe))
                                                                                ipv1_a1q7
                                                                                w5_X2Eu
                                                                                (w4_X2Ew
                                                                                 `cast` (GHC.Prim.State#
                                                                                           (Sym
                                                                                              <(Control.Monad.Primitive.TFCo:R:PrimStateST
                                                                                                  <s_aIe>)>)
                                                                                         :: GHC.Prim.State#
                                                                                              s_aIe
                                                                                              ~#
                                                                                            GHC.Prim.State#
                                                                                              (Control.Monad.Primitive.PrimState
                                                                                                 (GHC.ST.ST
                                                                                                    s_aIe))))
                                                                         of _
                                                                         { (# ipv9_X1wj, ipv10_X1wl #) ->
                                                                         let {
                                                                           $j2_X2BE
                                                                             :: GHC.Prim.Int#
                                                                                -> (# GHC.Prim.State#
                                                                                        s_aIe,
                                                                                      GHC.Types.Int #)
                                                                           [LclId,
                                                                            Arity=1,
                                                                            Str=DmdType L]
                                                                           $j2_X2BE =
                                                                             \ (y2_X15A
                                                                                  :: GHC.Prim.Int#) ->
                                                                               case GHC.Prim.readIntArray#
                                                                                      @ (Control.Monad.Primitive.PrimState
                                                                                           (GHC.ST.ST
                                                                                              s_aIe))
                                                                                      ipv1_a1q7
                                                                                      y2_X15A
                                                                                      ipv9_X1wj
                                                                               of _
                                                                               { (# ipv11_X1A5, ipv12_X1A8 #) ->
                                                                               case GHC.Prim.<#
                                                                                      ipv10_X1wl
                                                                                      100000000000
                                                                               of _ {
                                                                                 GHC.Types.False ->
                                                                                   (# ipv11_X1A5
                                                                                      `cast` (GHC.Prim.State#
                                                                                                <(Control.Monad.Primitive.TFCo:R:PrimStateST
                                                                                                    <s_aIe>)>
                                                                                              :: GHC.Prim.State#
                                                                                                   (Control.Monad.Primitive.PrimState
                                                                                                      (GHC.ST.ST
                                                                                                         s_aIe))
                                                                                                   ~#
                                                                                                 GHC.Prim.State#
                                                                                                   s_aIe),
                                                                                      GHC.Types.I#
                                                                                        wild7_X5S #);
                                                                                 GHC.Types.True ->
                                                                                   case GHC.Classes.divInt#
                                                                                          w5_X2Eu 2
                                                                                   of ww7_X2AY
                                                                                   { __DEFAULT ->
                                                                                   let {
                                                                                     x3_X1uN [Dmd=Just L]
                                                                                       :: GHC.Prim.Int#
                                                                                     [LclId,
                                                                                      Str=DmdType]
                                                                                     x3_X1uN =
                                                                                       GHC.Prim.+#
                                                                                         ww7_X2AY
                                                                                         1 } in
                                                                                   case GHC.Prim.>=#
                                                                                          x3_X1uN 0
                                                                                   of _ {
                                                                                     GHC.Types.False ->
                                                                                       case lvl15_r2JG
                                                                                              @ s_aIe
                                                                                              x1_a1iN
                                                                                              x3_X1uN
                                                                                       of wild10_00 {
                                                                                       };
                                                                                     GHC.Types.True ->
                                                                                       case GHC.Prim.<#
                                                                                              x3_X1uN
                                                                                              x1_a1iN
                                                                                       of _ {
                                                                                         GHC.Types.False ->
                                                                                           case lvl16_r2JH
                                                                                                  @ s_aIe
                                                                                                  x1_a1iN
                                                                                                  x3_X1uN
                                                                                           of wild11_00 {
                                                                                           };
                                                                                         GHC.Types.True ->
                                                                                           case (GHC.Prim.writeIntArray#
                                                                                                   @ (Control.Monad.Primitive.PrimState
                                                                                                        (GHC.ST.ST
                                                                                                           s_aIe))
                                                                                                   ipv1_a1q7
                                                                                                   x3_X1uN
                                                                                                   (GHC.Prim.+#
                                                                                                      ipv12_X1A8
                                                                                                      1)
                                                                                                   ipv11_X1A5)
                                                                                                `cast` (GHC.Prim.State#
                                                                                                          <(Control.Monad.Primitive.TFCo:R:PrimStateST
                                                                                                              <s_aIe>)>
                                                                                                        :: GHC.Prim.State#
                                                                                                             (Control.Monad.Primitive.PrimState
                                                                                                                (GHC.ST.ST
                                                                                                                   s_aIe))
                                                                                                             ~#
                                                                                                           GHC.Prim.State#
                                                                                                             s_aIe)
                                                                                           of ipv13_X182
                                                                                           { __DEFAULT ->
                                                                                           case GHC.Prim.>=#
                                                                                                  x3_X1uN
                                                                                                  0
                                                                                           of _ {
                                                                                             GHC.Types.False ->
                                                                                               case lvl17_r2JI
                                                                                                      @ s_aIe
                                                                                                      x3_X1uN
                                                                                                      x1_a1iN
                                                                                               of wild12_00 {
                                                                                               };
                                                                                             GHC.Types.True ->
                                                                                               case GHC.Prim.<#
                                                                                                      x3_X1uN
                                                                                                      x1_a1iN
                                                                                               of _ {
                                                                                                 GHC.Types.False ->
                                                                                                   case lvl18_r2JJ
                                                                                                          @ s_aIe
                                                                                                          x3_X1uN
                                                                                                          x1_a1iN
                                                                                                   of wild13_00 {
                                                                                                   };
                                                                                                 GHC.Types.True ->
                                                                                                   case (GHC.Prim.writeIntArray#
                                                                                                           @ (Control.Monad.Primitive.PrimState
                                                                                                                (GHC.ST.ST
                                                                                                                   s_aIe))
                                                                                                           ipv1_a1q7
                                                                                                           x3_X1uN
                                                                                                           (GHC.Prim.+#
                                                                                                              ipv10_X1wl
                                                                                                              1)
                                                                                                           (ipv13_X182
                                                                                                            `cast` (GHC.Prim.State#
                                                                                                                      (Sym
                                                                                                                         <(Control.Monad.Primitive.TFCo:R:PrimStateST
                                                                                                                             <s_aIe>)>)
                                                                                                                    :: GHC.Prim.State#
                                                                                                                         s_aIe
                                                                                                                         ~#
                                                                                                                       GHC.Prim.State#
                                                                                                                         (Control.Monad.Primitive.PrimState
                                                                                                                            (GHC.ST.ST
                                                                                                                               s_aIe)))))
                                                                                                        `cast` (GHC.Prim.State#
                                                                                                                  <(Control.Monad.Primitive.TFCo:R:PrimStateST
                                                                                                                      <s_aIe>)>
                                                                                                                :: GHC.Prim.State#
                                                                                                                     (Control.Monad.Primitive.PrimState
                                                                                                                        (GHC.ST.ST
                                                                                                                           s_aIe))
                                                                                                                     ~#
                                                                                                                   GHC.Prim.State#
                                                                                                                     s_aIe)
                                                                                                   of ipv14_X17O
                                                                                                   { __DEFAULT ->
                                                                                                   $wa1_X2Ez
                                                                                                     (GHC.Prim.-#
                                                                                                        wild7_X5S
                                                                                                        1)
                                                                                                     ipv14_X17O
                                                                                                   }
                                                                                               }
                                                                                           }
                                                                                           }
                                                                                       }
                                                                                   }
                                                                                   }
                                                                               }
                                                                               } } in
                                                                         case ww4_X11K
                                                                         of wild8_aZS {
                                                                           __DEFAULT ->
                                                                             case GHC.Classes.modInt#
                                                                                    ipv10_X1wl
                                                                                    wild8_aZS
                                                                             of ww7_aZX
                                                                             { __DEFAULT ->
                                                                             $j2_X2BE ww7_aZX
                                                                             };
                                                                           (-1) -> $j2_X2BE 0;
                                                                           0 ->
                                                                             case GHC.Err.divZeroError
                                                                             of wild9_00 {
                                                                             }
                                                                         }
                                                                         } } in
                                                                   case ww3_aZQ of wild8_aZS {
                                                                     __DEFAULT ->
                                                                       case GHC.Classes.modInt#
                                                                              wild7_X5S wild8_aZS
                                                                       of ww7_aZX { __DEFAULT ->
                                                                       $w$j1_X2EI ww7_aZX
                                                                       };
                                                                     (-1) -> $w$j1_X2EI 0;
                                                                     0 ->
                                                                       case GHC.Err.divZeroError
                                                                       of wild9_00 {
                                                                       }
                                                                   };
                                                                 0 -> (# w4_X2Ew, lvl19_r2JK #)
                                                               }; } in
                                                         $wa1_X2Ez
                                                           (GHC.Prim.-# wild_X2S 1) ipv8_X14f
                                                         }
                                                     }
                                                 }
                                                 }
                                             }
                                         }
                                         }
                                     }
                                     } } in
                               case ww4_X11K of wild1_aZS {
                                 __DEFAULT ->
                                   case GHC.Classes.modInt# ipv4_a1tc wild1_aZS
                                   of ww5_aZX { __DEFAULT ->
                                   $j1_s2ys ww5_aZX
                                   };
                                 (-1) -> $j1_s2ys 0;
                                 0 -> case GHC.Err.divZeroError of wild3_00 { }
                               }
                               }
                               } } in
                         case ww3_aZQ of wild1_aZS {
                           __DEFAULT ->
                             case GHC.Classes.modInt# wild_X2S wild1_aZS
                             of ww4_aZX { __DEFAULT ->
                             $w$j_s2BD ww4_aZX
                             };
                           (-1) -> $w$j_s2BD 0;
                           0 -> case GHC.Err.divZeroError of wild3_00 { }
                         }
                         };
                       0 -> (# w_s2Bx, lvl19_r2JK #)
                     } } in
               let {
                 a_s11i [InlPrag=INLINE[0]]
                   :: GHC.Types.Int
                      -> GHC.Prim.State# s_aIe
                      -> (# GHC.Prim.State# s_aIe, GHC.Types.Int #)
                 [LclId,
                  Arity=2,
                  Str=DmdType U(L)L,
                  Unf=Unf{Src=Worker=$wa_s2BC, TopLvl=False, Arity=2, Value=True,
                          ConLike=True, WorkFree=True, Expandable=True,
                          Guidance=ALWAYS_IF(unsat_ok=True,boring_ok=False)
                          Tmpl= \ (w_s2Bt [Occ=Once!] :: GHC.Types.Int)
                                  (w1_s2Bx [Occ=Once] :: GHC.Prim.State# s_aIe) ->
                                  case w_s2Bt of _ { GHC.Types.I# ww2_s2Bv [Occ=Once] ->
                                  $wa_s2BC ww2_s2Bv w1_s2Bx
                                  }}]
                 a_s11i =
                   \ (w_s2Bt :: GHC.Types.Int) (w1_s2Bx :: GHC.Prim.State# s_aIe) ->
                     case w_s2Bt of _ { GHC.Types.I# ww2_s2Bv ->
                     $wa_s2BC ww2_s2Bv w1_s2Bx
                     } } in
               a_s11i lvl9_r2Jz)
                ipv2_a10D } in
        case GHC.Prim.># 0 y_a15t of _ {
          GHC.Types.False ->
            letrec {
              a_s2zf [Occ=LoopBreaker]
                :: GHC.Prim.Int#
                   -> GHC.Prim.State# s_aIe -> (# GHC.Prim.State# s_aIe, () #)
              [LclId, Arity=2, Str=DmdType LL]
              a_s2zf =
                \ (x_a15x :: GHC.Prim.Int#) (s1_a10A :: GHC.Prim.State# s_aIe) ->
                  case GHC.Prim.>=# x_a15x 0 of _ {
                    GHC.Types.False ->
                      case lvl21_r2JM @ s_aIe x_a15x x1_a1iN of wild3_00 { };
                    GHC.Types.True ->
                      case GHC.Prim.<# x_a15x x1_a1iN of _ {
                        GHC.Types.False ->
                          case lvl22_r2JN @ s_aIe x_a15x x1_a1iN of wild3_00 { };
                        GHC.Types.True ->
                          case (GHC.Prim.writeIntArray#
                                  @ (Control.Monad.Primitive.PrimState (GHC.ST.ST s_aIe))
                                  ipv1_a1q7
                                  x_a15x
                                  0
                                  (s1_a10A
                                   `cast` (GHC.Prim.State#
                                             (Sym
                                                <(Control.Monad.Primitive.TFCo:R:PrimStateST
                                                    <s_aIe>)>)
                                           :: GHC.Prim.State# s_aIe
                                                ~#
                                              GHC.Prim.State#
                                                (Control.Monad.Primitive.PrimState
                                                   (GHC.ST.ST s_aIe)))))
                               `cast` (GHC.Prim.State#
                                         <(Control.Monad.Primitive.TFCo:R:PrimStateST <s_aIe>)>
                                       :: GHC.Prim.State#
                                            (Control.Monad.Primitive.PrimState (GHC.ST.ST s_aIe))
                                            ~#
                                          GHC.Prim.State# s_aIe)
                          of ipv2_X129 { __DEFAULT ->
                          case GHC.Prim.==# x_a15x y_a15t of _ {
                            GHC.Types.False -> a_s2zf (GHC.Prim.+# x_a15x 1) ipv2_X129;
                            GHC.Types.True -> (# ipv2_X129, GHC.Tuple.() #)
                          }
                          }
                      }
                  }; } in
            case a_s2zf
                   0
                   (ipv_a1q6
                    `cast` (GHC.Prim.State#
                              <(Control.Monad.Primitive.TFCo:R:PrimStateST <s_aIe>)>
                            :: GHC.Prim.State#
                                 (Control.Monad.Primitive.PrimState (GHC.ST.ST s_aIe))
                                 ~#
                               GHC.Prim.State# s_aIe))
            of _ { (# ipv2_X123, _ #) ->
            $j_s2za ipv2_X123
            };
          GHC.Types.True ->
            $j_s2za
              (ipv_a1q6
               `cast` (GHC.Prim.State#
                         <(Control.Monad.Primitive.TFCo:R:PrimStateST <s_aIe>)>
                       :: GHC.Prim.State#
                            (Control.Monad.Primitive.PrimState (GHC.ST.ST s_aIe))
                            ~#
                          GHC.Prim.State# s_aIe))
        }
        }
        }
    }
    }

Main.main2 :: GHC.Base.String
[GblId,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=False,
         ConLike=False, WorkFree=False, Expandable=False,
         Guidance=IF_ARGS [] 70 0}]
Main.main2 =
  case GHC.ST.runSTRep @ GHC.Types.Int Main.main3
  of _ { GHC.Types.I# ww_a2x3 ->
  GHC.Show.$wshowSignedInt 0 ww_a2x3 (GHC.Types.[] @ GHC.Types.Char)
  }

Main.main1
  :: GHC.Prim.State# GHC.Prim.RealWorld
     -> (# GHC.Prim.State# GHC.Prim.RealWorld, () #)
[GblId,
 Arity=1,
 Str=DmdType L,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=1, Value=True,
         ConLike=True, WorkFree=True, Expandable=True,
         Guidance=IF_ARGS [0] 50 0}]
Main.main1 =
  \ (eta_a16J :: GHC.Prim.State# GHC.Prim.RealWorld) ->
    GHC.IO.Handle.Text.hPutStr2
      GHC.IO.Handle.FD.stdout Main.main2 GHC.Types.True eta_a16J

Main.main :: GHC.Types.IO ()
[GblId,
 Arity=1,
 Str=DmdType L,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=0, Value=True,
         ConLike=True, WorkFree=True, Expandable=True,
         Guidance=ALWAYS_IF(unsat_ok=True,boring_ok=True)}]
Main.main =
  Main.main1
  `cast` (Sym <(GHC.Types.NTCo:IO <()>)>
          :: (GHC.Prim.State# GHC.Prim.RealWorld
              -> (# GHC.Prim.State# GHC.Prim.RealWorld, () #))
               ~#
             GHC.Types.IO ())

Main.main4
  :: GHC.Prim.State# GHC.Prim.RealWorld
     -> (# GHC.Prim.State# GHC.Prim.RealWorld, () #)
[GblId,
 Arity=1,
 Str=DmdType L,
 Unf=Unf{Src=<vanilla>, TopLvl=True, Arity=1, Value=True,
         ConLike=True, WorkFree=True, Expandable=True,
         Guidance=IF_ARGS [0] 30 0}]
Main.main4 =
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
  Main.main4
  `cast` (Sym <(GHC.Types.NTCo:IO <()>)>
          :: (GHC.Prim.State# GHC.Prim.RealWorld
              -> (# GHC.Prim.State# GHC.Prim.RealWorld, () #))
               ~#
             GHC.Types.IO ())


------ Local rules for imported ids --------
"SPEC GHC.Real.^ [GHC.Types.Int, GHC.Integer.Type.Integer]" [ALWAYS]
    forall ($dNum_s11p :: GHC.Num.Num GHC.Types.Int)
           ($dIntegral_s11r :: GHC.Real.Integral GHC.Integer.Type.Integer).
      GHC.Real.^ @ GHC.Types.Int
                 @ GHC.Integer.Type.Integer
                 $dNum_s11p
                 $dIntegral_s11r
      = Main.$s^


Linking b ...
