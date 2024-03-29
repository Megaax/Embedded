#ifndef NVIC_private_H
#define NVIC_private_H


//0xE000E100 BASE ADRESS
#define NVIC_ISER0 *((u32*)0xE000E100)/*ENABLE INTERRUPT FORM 0 TO 31  */
#define NVIC_ISER1 *((u32*)0xE000E104)/*ENABLE INTERRUPT FORM 32 TO 59 */

#define NVIC_ICER0 *((u32*)0xE000E180)/*DISABLE INTERRUPT FORM 0 TO 31   */
#define NVIC_ICER1 *((u32*)0xE000E184)/*DISABLE INTERRUPT FORM 32 TO 59  */

#define NVIC_ISPR0 *((u32*)0xE000E200)/*SET PENDING FLAG (FOR TESTING AND DEBUGGING) FORM 0 TO 31   */
#define NVIC_ISPR1 *((u32*)0xE000E204)/*SET PENDING FLAG (FOR TESTING AND DEBUGGING) FORM 32 TO 59  */

#define NVIC_ICPR0 *((u32*)0xE000E280)/*CLEAR PENDING FLAG (FOR TESTING AND DEBUGGING) FORM 0 TO 31   */
#define NVIC_ICPR0 *((u32*)0xE000E284)/*CLEAR PENDING FLAG (FOR TESTING AND DEBUGGING) FORM 32 TO 59  */

#define NVIC_IABR0 *((u32*)0xE000E300)/*GET PENDING FLAG VALUE FROM 0 TO 31 */
#define NVIC_IABR1 *((u32*)0xE000E304)/*GET PENDING FLAG VALUE FROM 32 TO 59*/









#endif 
