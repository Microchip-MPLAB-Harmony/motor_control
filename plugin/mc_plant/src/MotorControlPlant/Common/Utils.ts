export function getIndex(selectedValue: any, array: any) {
    return array.findIndex(((obj: any) => obj === selectedValue));
}