/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
  const err = (t) => {throw new Error(t)};

    return {
        toBe:    (v) => v === val || err("Not Equal"),
        notToBe: (v) => v !== val || err("Equal")
    };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */