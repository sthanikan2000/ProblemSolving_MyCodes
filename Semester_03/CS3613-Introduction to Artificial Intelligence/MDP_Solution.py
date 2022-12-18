###------------- Additional Functions Needed ----------------------------------------------------------

#Get the utility of the state from previous iteration
def get_pre_u(U, r, c, action):
    row_move, col_mov = stochastic_actions[action]
    new_r, new_c = r+row_move, c+col_mov
    if new_r < 0 or new_c < 0 or new_r >= rows or new_c >= columns: # collide with the boundary
        return U[r][c]
    else:
        return U[new_r][new_c]

# find the Best action and the optimal utility from set of action's utilities of a given state
def findUtilityAndBestAction(E,r,c,rewards):
    E_optimal=max(E)
    BEST_ACTIONS=[]
    for i in range(actions):
        if E[i] ==E_optimal:
            BEST_ACTIONS.append(all_possible_action_names[i])
    # Return V_optimal, bestActionsFromGivenState
    return (rewards[r][c] + gamma * E_optimal,BEST_ACTIONS)

def isEqualBestActions(A1,A2):
    for r in range(rows):
        for c in range(columns):
            if A1[r][c] != A2[r][c]:
                return False
    return True

# Print Visualization of Grid World
def printWorld(arr, PrintPolicy=False):
    res = ""
    for r in range(rows):
        res += "-"*37
        res += "\n|"
        for c in range(columns):
            if r == 1 and c == 2:
                if PrintPolicy:
                    val = "Terminal"
                else:
                    val = "+1"
            else:
                if PrintPolicy:
                    val = arr[r][c][0]
                else:
                    val = str(arr[r][c])
            res += " " + val[:9].ljust(9) + " |"
        res += "\n"
    res += "-"*37
    print(res)

###--------------------------------------------------------------------------------------------------
    
###>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> get_state_utilities funnction <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
def get_state_utilities(U,rewards):
    iteration=0
    BestActions=[[None,None,None],[None,None,None]] # Initialize Policy
    
    con1=False # condition for whether policy converged
    while True:
        iteration += 1
        nextU = [[0, 0, 0], [0, 0, 1]]
        nextBestActions=[[None,None,None],[None,None,None]]
        
        delta = 0 # δ

        print(">>> Expected Utilities for taking each action North, East, South, West & DoNothing respectively \n    from given state during iteration #%i:"%(iteration))
        for r in range(rows):
            for c in range(columns):
                if (r == 1 and c == 2):
                    continue
                E=[] # To store expected Utilities for taking each action
                for action in range(actions):
                    # Calculate the Expected utility of a state given an action
                    if action == 4:#For DoNothing
                        exp_u = U[r][c]
                    else:
                        exp_u = 0.05 * get_pre_u(U, r, c, action-1) + 0.9 * get_pre_u(U, r, c, action) + 0.05 * get_pre_u(U, r, c, (action+1)%4)
                    E.append(exp_u)
                    
                print("     state-%i: "%(states[r][c])+str(E))
                
                ( nextU[r][c], nextBestActions[r][c] )=findUtilityAndBestAction(E,r,c,rewards)
                
                delta = max(delta, abs(nextU[r][c]-U[r][c]))
        print("")
        if isEqualBestActions(BestActions,nextBestActions):
            if not(con1):
                iteration_policy_con = iteration-1  #Because it converges in previous iteration
                con1=True
        else:
            con1=False
            
        U = nextU
        BestActions=nextBestActions
        if delta < epsilon * (1-gamma) / gamma:
            iteration_utility_con=iteration
            U = nextU
            BestActions=nextBestActions
            break

        #following will visualize utility and policy after each iteration
        print(">>> Optimal Utilities after iteration #%i :"%(iteration))
        printWorld(U)
        print("\n>>> Optimal Policy after iteration #%i :"%(iteration))
        printWorld(BestActions,True)
        print("\n\n")

    print("\n>>> Policy Converges at iteration #%i"%(iteration_policy_con)) # Answer for On what iteration does the policy converge?
    print(">>> Best Policy at the Convergence :")
    printWorld(BestActions,True) # Answer for What is the best policy at the end?

    print("\n>>> Utilities Converges at iteration #%i"%(iteration_utility_con)) # Answer for How many iterations does it take the utilities to converge?

    return U
###>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

###----------------Grid World Datas--------------------------------------------------------------------
"""
#s(i) means state_i
----------------------------------------------
| s4 (ind=0,0) | s5 (ind=0,1) | s6 (ind=0,2) |
----------------------------------------------
| s1 (ind=1,0) | s2 (ind=1,1) | s3 (ind=1,2) |
----------------------------------------------
"""
states=[[4,5,6],[1,2,3]]
rows=2
columns=3

rewards=[[-0.1,-0.1,-0.05],[-0.1,-0.1,+1]]# Reward for each states 1 to 6; Here 3 is terminal state
gamma=0.999 # Discount(γ)
epsilon=0.01 # ε

actions=5
stochastic_actions=[(-1,0),(0,1),(1,0),(0,-1)]#North,East,South,West 
all_possible_action_names=["North \u2191","East \u2192","South \u2193","West \u2190","DoNothing \u25A1"]

###----------------------------------------------------------------------------------------------------

#Initialize utility
U=[[0,0,0],[0,0,0]]

FinalConvergedUtilities=get_state_utilities(U,rewards)

print(">>> Final Converged Utilities at convergence considering epsilon(\u03B5) :")
printWorld(FinalConvergedUtilities)









