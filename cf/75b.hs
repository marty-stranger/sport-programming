import Data.List
import Data.Monoid
import Data.Ord

solve myName lines =
		map snd $ sortBy compare costs
	where
		cost "posted" = 15
		cost "commented" = 10
		cost "likes" = 5

		fixName2 = takeWhile (/= '\'')
		parse [name1, action, _, name2', _] = (name1, cost action, fixName2 name2')
		parse [name1, action, name2', _] = (name1, cost action, fixName2 name2')

		lines' = map (parse . words) lines

		names = (nub $ map (\(name1, _, _) -> name1) lines' ++ map (\(_, _, name2) ->  name2) lines')
			\\ [myName]

		lines'' = filter (\(name1, _, name2) -> name1 == myName || name2 == myName) lines'

		items = map (\(name1, cost, _) -> (name1, cost)) lines'' ++
			map (\(_, cost, name2) -> (name2, cost)) lines''

		costs = [(s, name) | name <- names, let s = sum $ [snd i | i <- items, fst i == name]]

		compare =  flip (comparing fst) `mappend` comparing snd

main = do
	myName <- getLine
	_ <- getLine
	actions <- lines `fmap` getContents
	putStrLn $ unlines $ solve myName actions
