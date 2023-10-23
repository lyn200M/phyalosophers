/**
 * soit Tm = temps de manger
 * soit Td = temps de dormir
 * soit TM = temps au bout duquel il meurt s'il ne mange pas
 * soit Np = nombre de phylosophes et de fourchette
 * chaque philosophe mange avec 2 fourchettes. IL partage chque fourchete avec
 * un autre philosophe
 * Tm1=>Td1=>TM=>Tm1
 * >=>=>Tm2=>Td2=>TM>
 *
 * cas 1: Np est pair:
 * 		- Np/2 phylosophes peuvent manger a la fois (les nombre impaire 1, 3, 5, .., n-1 inclue puis paire)=> on a qu'un tour a gerer s'il ont le meme Tm
 * 		- En entree: TM > Tm
 * 		- Apres le premier manger: Td on s'en foue. TM > Tm
 * cas 2: Np est impair:
 * 		- Np/2 phylosophes impaire peuvent manger a la fois (les nombre inpaire 1, 3, 5, .., n. (n)exclue)
 * 		- Np/2 phylosophes paires peuvent manger ensuite (2, 4, .., n-1 (n-1 inclue))
 * 		- Le phylosophe n mange seule apres 2Tm d'attente et on reprend le cycle
 * 		=> TM > 2Tm (miniimum pour tout le monde)
 *
 * Implementation
 * -	quand un groupe de phylosphe utilise les ressourses je le bloque pour tout le reste jusqu'a ce qu'ils finissent
 * -	Un systeme qui choisis quel groupe de phylosophe utilise les ressources
 * -	chaque phylosophe est un thread, p1, p2,  ..., pn.
 * -
 *
 */

threads = [thread1, thread2, thread3, thread4, thread5]  // Tableau de threads
group1 = [thread1, thread3, thread5]  // Groupe des philosophes impairs
group2 = [thread2, thread4]  // Groupe des philosophes pairs

// Utilisation de mutex partagés pour les fourchettes
fork_mutexes = [mutex1, mutex2, mutex3, mutex4, mutex5]

// Pour les philosophes impairs (groupe 1)
for philosopher in group1:
    philosopher.start()

// Pour les philosophes pairs (groupe 2)
for philosopher in group2:
    philosopher.start()
